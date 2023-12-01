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



int main() {

// 1. Game start      

//    Determine if it's a new game or a continuation 
//      If it's a new game, initiate default game params and actions
//        Player color choice
//        Initiative dice roll who starts first
//        Default board setup
//      If it's a continuation of a game
//        Read game details from save file and assign params
//        Continue the game by going to the next player round

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
