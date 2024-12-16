#ifndef AA002CAB_54FA_497C_905E_A775BB47D41E
#define AA002CAB_54FA_497C_905E_A775BB47D41E
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Constants.h"
using namespace std;


void Start(){
    cout << "Welcome to Thiv's Blackjack!!!!\n\n"
         << "Rules: Standard blackjack rules with a slight twist.\n\n"
         << "Player closest to 21 wins! \n\n"
         << "Aces always count as 11 and you can bust on A-A, A-2,...,A-9.\n\n"
         << "Player always wins on a Blackjack no matter what the dealer pulls!\n\n"
         << "BlackJack pays 1 : 1\n\n"
         << "Dealer stands on all 17's\n\n"
         << "Play options:  \"H\" - Hit, \"S\" - Stand, \"D\" - Double.\n\n"
         << "A bet of '-1' or end of shoe terminates the game.\n\n"
         << "May the best player win!!!!" << endl;
}

int UpdateDeck(int total){
    total++;
    return total;
}

int GenerateCard(int arr[], int decks){
    int card = rand()%13;
    arr[card]++;
    while (arr[card]>(decks*4)){
        card = rand()%13;
        arr[card]++;
    }
    return card;
}

int Playerhit(int total, int arr[], int decks) {
    int newcard = GenerateCard(arr, decks) ;
    std::cout<<"Player new card is: "<<endl;
    drawCard(newcard);
    total =total + cardvalue[newcard];
    return total;
}

int Dealerhit(int total, int arr[], int decks){
     int newcard = GenerateCard(arr, decks) ;
    std::cout<<"Dealer new card is: "<<endl;
    drawCard(newcard);
    total =total + cardvalue[newcard];
    return total;
}

int doubleplay(int total, int arr[], int decks){
    int newcard = GenerateCard(arr, decks) ;
    std::cout<<"Player new card is: "<<endl;
    drawCard(newcard);
    total =total + cardvalue[newcard];
    return total;
}



#endif /* AA002CAB_54FA_497C_905E_A775BB47D41E */
