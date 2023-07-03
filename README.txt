Λαμπρόπουλος Κωνσταντίνος
Γκέργκη Δημήτρης

This project is a card game written in C++.The game takes place on the GameBoard in which there are players.
Each players represents and honourable(or...dishonourable) oppressor who manages his (japanese type)
dynasty.Each player safekeeps his cards in specified regions of the GameBoard based on their state,for example
he draws from 2 decks of cards,his "hand" to use certain cards at different phases of the game,4 cards which
represent provinces of this dynasty etc.The main purpose of each player is to destroy the provinces of the rest of the players
and the safekeeping of at least one province of his.
The Fate Deck,has Green cards which represent specific abilities available to the oppressor(use of objects or followers) ,which the 
oppressor keeps at his hand and chooses at the appropriate phase of the game.The other deck,the Dynasty Deck,
has Black Cards which represent great personalities or properties which are part of the dynasty and are placed
in front of the player.Each Deck has at least 40 cards and a max limit of cards (60).The player can have at his hand 
at most 6 cards.Each oppressor is characterized by his family's honour,which is given to him by a special card given at the
beginning of the game,called StrongHold.
The Game takes place on multiple rounds of multiple phases,and the players play on descending order based on
their Honour.

This implementation is a simpler version of the Legend of the Five Rings,and a link with more details lies below:
https://www.fantasyflightgames.com/en/products/legend-of-the-five-rings-the-card-game/

There is a makefile ,which by the use of the command make ,creates the executable main.By running main the game starts with 2 players.
Note that the game is not fully implemented and bugs may appear.

