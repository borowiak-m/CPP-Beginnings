/* BACKGAMMON GAME IN TERMINAL

UNDERSTANDING THE GAME DATA DICTIONARY
NOUNS:
diceD6
diceDoubling
player
gameBoard
boardPositions
middleBar
whitesHome
whitesBase
redsHome
redsBase
redCheckers
whiteCheckers            
gameStartIndicator       - who starts first
blockingNumberOfCheckers - number of checkers in position blocking a move onto the position
moveDirectionIdicator    - direction ( 24->1 "-" / 1->24 "+" ) reds move one direction, whites move the other direction
winPoints                
winCount                 

VERBS/ACTIONS:
redOrWhiteChoice         - player either plays reds or whites
diceRollStart            - there is a starting dice roll to determine order of play, who goes first
startDiceRollCompare     
diceRollInGame           
boardInitialSetup        - there is a set way how the board is setup at the geginning of the game
moveChecker              - checkers can move to a position on the board = starting position + roll dice number / or - roll dice depends on the movement direction
hitChecker               - hit opponents checker off a position onto the middle of the board / only when 1 oppositing checker, if more the move is illegal
moveCheckerToBase        - taking a checker off board into base, when all checkers in base = win game
moveLegalityCheck        - if there is 2 or more opponent's checkers then a board position is considered off limits = illegal
allBackHomeCheck         - check if all checkers are home = each player has defined home range of positions
middleBarCheck           - check if player has checkers in the middle of the board
winConditionCheck        - when all checkers are off board, in base
calculateWinningPoints   - points calculated when game ends, depending on the position of opponents 
moveToBasePriorityCheck  - checking which checkers have priority to move to the base from the board


[SAVING GAME STATUS:
When:
Game status is saved every round when board is updated.
How:
Game status is saved to a text file in a format variable1|variable2|variable3...etc, each having a precise position in the data format
- Game status params:   gameSerieNumber,      - current serie
                        gameMatchNumber,      - current match in a serie
                        gameRoundNumber,      - current round in a match
                        player1wins,          - player1 won matches in current game serie
                        player1color, 
                        player1name, 
                        player1diceroll,      - player1 dice roll values if they rolled, if not = 0 0 0 0
                        player2wins,          - player2 won matches in current game serie
                        player2color, 
                        player2name,          
                        player2diceroll,      - player2 dice roll values if they rolled, if not = 0 0 0 0
                        boardState            - number of each player's checkers per board position
]*/

#include <cstdio>
#include <cstring>
#include <filesystem>

const int BOARD_SIZE          = 24;
const int MAX_COLOR_SIZE      = 5;
const int MAX_NAME_SIZE       = 50;
const char * gameSaveFilename = "C:/Users/mariusz.borowiak/Documents/Dev/C++/Backgammon/gameSave.txt";

struct Position {
  int whiteCount;
  int redCount;
};

struct Player {
  int wins;
  int points;
  char name[MAX_NAME_SIZE];
  char color[MAX_COLOR_SIZE];
  int diceRolls[4];
};

struct GameDetails {
  int seriesNumber;
  int matchNumber;
  int roundNumber;
};

void readPlayerData(FILE* file, Player& player) {
  fscanf(file, "%d|%d|%[^|]|%[^|]|", &player.wins, &player.points, &player.name, &player.color);
  for (int i = 0; i < 4; i++) {
    fscanf(file,"%d|", &player.diceRolls[i]);
  }
}

void readBoardData(FILE* file, Position boardState[BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++){
    fscanf(file, "%d|%d|", &boardState[i].whiteCount, &boardState[i].redCount);
  }
}

void readGameData(FILE* file, GameDetails& gameDetails) {
  fscanf(file, "%d|%d|%d|", &gameDetails.seriesNumber, &gameDetails.matchNumber, &gameDetails.roundNumber);
}

bool fileExists(const char* filename) {
  return std::filesystem::exists(filename);
}

bool isFileEmpty(FILE* file) {
  // Move to end of file
  fseek(file, 0, SEEK_END);
  // Get the size of the file
  long size = ftell(file);
  // Afterwards reset file pointer
  rewind(file);
  return size == 0; 
}

bool readGameState(GameDetails& gameDetails, Player& player1, Player& player2, Position boardState[BOARD_SIZE]){
  // If the file doesn't exist OR if file exists but is empty, return false and handle lack of a game save in main
  if (!fileExists(gameSaveFilename) || (fileExists(gameSaveFilename) && isFileEmpty(fopen(gameSaveFilename,"r")))) return false;
  FILE* file = fopen(gameSaveFilename,"r");
  readGameData(file, gameDetails);
  readPlayerData(file, player1);
  readPlayerData(file, player2);
  readBoardData(file, boardState);
  fclose(file);
  return true; // successfull game save read
}

void initializeGameDetails(GameDetails& gameDetails) {
  gameDetails.seriesNumber  = 1;
  gameDetails.matchNumber   = 1;
  gameDetails.roundNumber   = 1;
}

void initializePlayer(Player& player, const char* name, const char* color) {
  strcpy(player.name, name);
  strcpy(player.color, color);
  player.wins = 0;
  player.points = 0;
  memset(player.diceRolls, 0, sizeof(player.diceRolls));
}

void initializeBoard(Position boardState[BOARD_SIZE]) {
  boardState[23].whiteCount = 2; // Board position 24
  boardState[12].whiteCount = 5; // Board position 13
  boardState[7].whiteCount  = 3; // Board position 8
  boardState[5].whiteCount  = 5; // Board position 6
  boardState[0].redCount    = 2; // Board position 1
  boardState[11].redCount   = 5; // Board position 10
  boardState[16].redCount   = 3; // Board position 17
  boardState[18].redCount   = 5; // Board position 19
}

bool initializeNewGame(GameDetails& gameDetails, Player& player1, Player& player2, Position boardState[BOARD_SIZE]) {
  initializeGameDetails(gameDetails);
  initializePlayer(player1, "User", "white");
  initializePlayer(player2, "ComputerPlayer", "red");
  initializeBoard(boardState);
}


int main() {
  GameDetails gameDetails;
  Player player1 = {}, player2 = {};
  Position boardState[BOARD_SIZE] = {{0,0}};

// 1. Game start      

//    Determine if it's a new game or a continuation 
//      If it's a continuation of a game
//        Read game details from save file and assign params
  bool isNewGame = readGameState(gameDetails, player1, player2, boardState);
  if (!isNewGame) {
//        Continue the game by going to the next player round
  } else {
    initializeNewGame(gameDetails, player1, player2, boardState);
  }
//      If it's a new game, initiate default game params and actions
//        Player color choice
//        Initiative dice roll who starts first
//        Default board setup


// 2. Game logic

//    Game is in progress as long as both players do not have all their checkers in thir base. Once one of them does, it is the win condition and game ends.
//      When game ends, win count and winning points are updated, game final save is done, and moved from current game save to game history file

//    Each round the following actions happen: 
//      Player rolls 2 d6 dice for movement
//      Based on dice results all legal movements are determined (if any checkers are in the middle of the board, they need to be moved as a priority)
//      Player makes choice where to move checkers
//      Board gets updated on screen, and game is saved to file 
//    

  return 0;
}
