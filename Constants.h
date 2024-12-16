#ifndef B8F4B0EB_13F8_4FE7_AFE3_69B5203E81B2
#define B8F4B0EB_13F8_4FE7_AFE3_69B5203E81B2

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int cardvalue[13]={11,2,3,4,5,6,7,8,9,10,10,10,10};


void drawCard(int card){

    if (card == 0){
        cout<<"  --- \n | A | \n  ---  "<<endl;
    }
    
    if (card == 1){
        cout<<"  --- \n | 2 | \n  ---  "<<endl;;
    }

    if (card == 2){
        cout<<"  --- \n | 3 | \n  ---  "<<endl;;
    }

    if (card == 3){
        cout<<"  --- \n | 4 | \n  ---  "<<endl;;
    }

    if (card == 4){
        cout<<"  --- \n | 5 | \n  ---  "<<endl;
    }

    if (card == 5){
        cout<<"  --- \n | 6 | \n  ---  "<<endl;
    }

    if (card == 6){
        cout<<"  --- \n | 7 | \n  ---  "<<endl;
    }

    if (card == 7){
        cout<<"  --- \n | 8 | \n  ---  "<<endl;
    }

    if (card == 8){
        cout<<"  --- \n | 9 | \n  ---  "<<endl;
    }

    if (card == 9){
        cout<<"  --- \n | T | \n  ---  "<<endl;
    }

    if (card == 10){
       cout<<"  --- \n | J | \n  ---  "<<endl;
    }

    if (card == 11){
       cout<<"  --- \n | Q | \n  ---  "<<endl;
    }

    if (card == 12){
        cout<<"  --- \n | K | \n  ---  "<<endl;
    }
}

#endif /* B8F4B0EB_13F8_4FE7_AFE3_69B5203E81B2 */
