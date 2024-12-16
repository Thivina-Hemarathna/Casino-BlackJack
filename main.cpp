//BlackJack V1.0
//Thivina Hemarathna 2024/12
//Update on 2024/12/15
//Stand, Hit and Double work
//Slit needs to be implemented.


#include <iostream>
#include <stdlib.h>
#include <string>
#include "playoption.h"
#include "Constants.h"

using namespace std;


int main(){

    //Decalarations
    string username, move;
    int CardCount[13]={0};
    int bet = 0, playertotal = 0, dealertotal = 0, decktotal = 0, buy =0, decks = 0;

    //Random card choices
    srand(time(0));

    Start();

    //Player initialization
    cout<<"Enter you name : "<< endl;
    cin >>username;
    cout<<"Welcome to Blackjack "<< username << "!"<<endl;
    cout<<"Enter the number of decks (1-6) you want to play: "<<endl;
    cin>>decks;

    //validate decks;
    while(decks<1 || decks>6){
        cout<<"Invalid number of decks!!"<<endl;
        cout<<"Re-enter number of decks(1-6): "<<endl;
        cin >> decks;
    }

    cout<<"Enter the buying amount : "<<endl;
    cin >> buy; 
    //buy in validation
    while (buy<=0){
        cout<<"Invalid Buy In!!"<<endl;
        cout<<"Enter valid buy in: "<<endl;
        cin>>bet;
    }

    cout<<"Enter bet amount: "<<endl;
    cin>>bet;
    //bet validation
    while (bet>buy){
        cout<<"Invalid Bet!!"<<endl;
        cout<<"Enter valid bet: "<<endl;
        cin>>bet;
    }

    buy = buy - bet;

    //loop for game play
    while (bet > 0 && decktotal<=((decks * 52)-10) && buy>=0){

        cout <<"Let's play!!"<<endl;
        cout<<"PLayer bet is: "<<bet<<endl;

            //Generating hands
            int playercard1 = GenerateCard(CardCount,decks) ;
                decktotal=UpdateDeck(decktotal);

            int dealercard1 = GenerateCard(CardCount,decks) ;
                decktotal=UpdateDeck(decktotal);

            int playercard2 = GenerateCard(CardCount,decks) ;
                decktotal=UpdateDeck(decktotal);

            int dealercard2 = GenerateCard(CardCount,decks) ;
                decktotal=UpdateDeck(decktotal);
            
            dealertotal= cardvalue[dealercard1]+cardvalue[dealercard2];

            playertotal = cardvalue[playercard1] + cardvalue[playercard2];

            cout<<"Player Card 1: "<<endl;

                drawCard(playercard1);
            
            cout<<"Player 2nd Card: "<<endl;

                drawCard(playercard2);

            cout<<"Player hand value is: "<<playertotal<<endl;

            cout<<"Dealer Card 1: "<<endl;

                drawCard(dealercard1);
            

        //Act based on player choice.
        while (playertotal<21){

            cout << "next move :"<<endl;
            cin >> move ;
            while ((move != "H") && (move != "S") && (move != "D") || (move == "D" && buy < bet * 2)){
                cout <<"Invalid move!!"<<endl;
                cout <<"Re-enter valid move: "<<endl;
                cin>>move ;
            }

                if (move == "H"){
                    playertotal = Playerhit(playertotal,CardCount,decks);
                    cout<<"New player total is: "<<playertotal<<endl;
                        decktotal=UpdateDeck(decktotal);
                }

                if (move == "S"){
                    break;
                }

                if (move == "D"){
                    break;
                }
        }

                if (move == "D"){
                    cout<<"Player new bet value is: "<<bet*2<<endl;
                    cout<<"Player balance is : "<<buy - bet<<endl;
                    playertotal = doubleplay(playertotal,CardCount,decks);
                    cout<<"New player total is: "<<playertotal<<endl;
                        decktotal=UpdateDeck(decktotal);
                }


                    cout<<endl<<"Dealer Card 2: "<<endl;
                    drawCard(dealercard2);
                    cout<<endl<<"Dealer total is: "<<dealertotal<<endl;

                if (cardvalue[playercard1] + cardvalue[playercard2] == 21){
                    cout<<"Congratulations on the Black Jack!!"<<endl;
                    buy = buy * (2*bet);
                    cout<<"Player balance is: "<<buy <<endl;
                    break;
                }
                if (playertotal>21){
                    cout<<"Player Bust, dealer wins"<<endl;
                    cout<<"Player balance is: "<<buy<<endl;
                }

                while (dealertotal<17 && playertotal <=21){
                        dealertotal=Dealerhit(dealertotal,CardCount,decks);
                        cout<<"New dealer total is: "<<dealertotal<<endl;
                            decktotal=UpdateDeck(decktotal);
                }

                if (dealertotal>21){
                    cout<<"Dealer bust, you win!"<<endl;
                    buy = buy + (2*bet);
                    cout<<"Player balance is: "<<buy<<endl;
                }
                else if (dealertotal == playertotal){
                    cout<<"Push"<<endl;
                    buy=buy+bet;
                    cout<<"Player balance is: "<<buy<<endl;
                }
                else if (dealertotal>playertotal){
                    cout<<"Dealer wins"<<endl;
                    cout<<"Player balance is: "<<buy<<endl;
                }
                else if (playertotal > dealertotal){
                    cout<<"PLayer wins"<<endl;
                    buy = buy + (2*bet);
                    cout<<"Player balance is "<<buy<<endl;
                }

    if (decktotal > (decks * 52)-10){
        break;
    }

    if (buy == 0){
        break;
    }

    cout<<"Enter the betting amount : "<<endl;
    cin >>bet ;
    buy = buy - bet;

    }

        if (decktotal>(decks * 52)-10){
            cout<<"End of shoe"<<endl;
            cout<<"Restart game."<<endl;
        }
        if (buy < 0){
            cout<<"Current balance is zero"<<endl;
            cout<<"Restart and add more money"<<endl;
        }
        cout<<"Thank you for playing Blackjack!"<<endl;

            //counting the deck of cards//
            for (int i=0; i<13; i++){
                CardCount[i] = 0;
            }
            decktotal = 0;

    return 0;
}
