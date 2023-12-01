
/* 
rzeczowniki:
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
    moveDirectionIdicator    - direction ( 24->1 "-" / 1->24 "+" )
    winPoints                - punktacja
    winCount                 - liczba zwyciestw

czasowniki:
    redOrWhiteChoice         - wymor kolou pionkow ( = pozycji na planszy, bazy i domu oraz kierunku ruchow)
    diceRollStart            - poczatkowy rzut kosci
    startDiceRollCompare     - porownanie wynikow kosci
    diceRollInGame           - rzuc koscmi
    boardInitialSetup        - pierwsze ustawienie planszy
    moveChecker              - ruch pionka z pozycji startowej na pozycje plus oczka kosci
    hitChecker               - zbicie pionka z pozycji (tylko kiedy = 1 pionek przeciwnika na pozycji)
    moveCheckerToBase        - zdjecie pionka z planszy do bazy
    moveLegalityCheck        - czy mozna sie ruszyc z poz startowej plus oczka z kosci (jesli >=2 pionki przeciwnika to nie) 
    allBackHomeCheck         - czy wszystkie pionki sa w domu
    middleBarCheck           - czy jest moj pionek na srodku planszy
    winConditionCheck        - czy wszystkie pionki sa w bazie
    calculateWinningPoints   - kalulacja punktacji (w zaleznosci od ukladu planszy)
    moveToBasePriorityCheck  - spr ktory pionek moze wejsc do bazy pierwszy (ten najdalej)


    [ZAPISYWANE W TRAKCIE GRY:
        - Stan serii, czy kontynuacje czy nowa seria
        - Stan rozgrywki:   kolor pionkow, pozycje wszystkich pionkow, kogo ruch, 
                            rzut kosci dla ruchu (domyslnie 0, 0, po rzucie update na X, X z wyniku rzutu)
    ]*/


    // 1. Rozpoczecie gry       (pojedyncza czy seria do okreslonej liczby wygranych ??)

      //  - sprawdzenie numeru serii/rozgrywki 
      //  - wybor koloru pionkow przez gracza
      //  - ustawienie planszy (umieszczenie pionkow na ustalonych pozycjach)
      //  - poczatkowy rzut koscia, 2x D6 dla gracza, 2x D6 dla komputera
      //  - porownanie wynikow i ustalenie pierszenstwa gry

    // 2. Gra

       // - pierwszy gracz rzuca kosia 2x D6 dla ruchow
       // - wedluch rezultatow rzutu koscmi wygeneruj liste legalnych ruchow
       // - jesli graczem jest komputer, zagraj pierwszy ruch z listy
       // - jesli graczem jest czlowiek, podaj liste legalnych ruchow do wyboru


       int main() {
        
       }
