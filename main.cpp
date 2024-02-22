#include <iostream>

using namespace std;

/*This program is for a juice machine at a gym that sells various types of juices
such as orange, apple, mango and strawberry */

//A class to implement the operations of a cash register.
class cashRegister{
public:
    int getCurrentBalance() const; //Function to show the current amount in the cash register
    void acceptAmount(int amountIn); //Function to receive the amount deposited by the customer.

    cashRegister(int cashIn); //constructor, sets the cash in the register to a specific amount.
private:
    int cash; //variable to store the cash in the register
};

//Class for the dispenser to implement a dispenser.

class dispenserType{
public:
    int getNoOfItems() const; //Function to show the number of items in the machine
    int getCost() const; //Function to show the cost of the item.
    void makeSale(); //Function to reduce the number of items by 1 after a sale

    dispenserType(int setNoOfItems, int setCost); //Function to set the cost and number of items in the dispenser.

private:
    int items; //variable to store the number of items in the dispenser
    int cost; //variable to store the cost of an item.
};

void selection();
void sellProduct(dispenserType& product, cashRegister& counter);



int main()
{
    cashRegister counter(500); //initializing the register with a set amount.

    //creating the juices for the dispenser
    dispenserType orange(100, 50);
    dispenserType apple(100, 65);
    dispenserType mango(70, 80);
    dispenserType strawberry(165, 85);

    int choice;
    selection();
    cin>> choice;

while(choice !=9){
    switch(choice){
case 1:
    sellProduct(orange, counter);
    break;
case 2:
    sellProduct(apple, counter);
    break;
case 3:
    sellProduct(mango, counter);
    break;
case 4:
    sellProduct(strawberry, counter);
    break;
default:
    cout<<"Invalid selection!!!"<<endl;
    break;
    }
     selection();
    cin>> choice;
}
    return 0;
} //end main

//function definitions.

cashRegister::cashRegister(int cashIn){
    if(cashIn >= 0)
        cash = cashIn;
    else
        cash = 500;
}

void cashRegister::acceptAmount(int amountIn){
    cash += amountIn;
}

int cashRegister::getCurrentBalance()const{
    return cash;
}

dispenserType::dispenserType(int setNoOfItems, int setCost){
    if(setNoOfItems>=0)
        items = setNoOfItems;
    else
        items =100;
    if(setCost>=0)
        cost= setCost;
    else
        cost= 50;
}

int dispenserType::getNoOfItems() const{
    return items;
}

int dispenserType::getCost() const{
    return cost;
}

void dispenserType::makeSale(){
    items--;
}

void selection(){
    cout<<"\nWelcome to our Juice Machine "<<endl;
    cout<<"To select an item, Enter "<<endl;
    cout<<"1 for Orange Juice (50 cents)"<<endl;
    cout<<"2 for Apple Juice (65 cents)"<<endl;
    cout<<"3 for Mango Juice (80 cents)"<<endl;
    cout<<"4 for Strawberry Juice (85 cents)"<<endl;
    cout<<"9 to exit"<<endl;
    cout<<"Your choice: ";
}

void sellProduct(dispenserType& product, cashRegister& counter){
    int amount;
    int amountR;
    if(product.getNoOfItems() > 0){
        cout<<"This item costs "<<product.getCost()<<"cents, enter the amount"<<endl;
        cin >> amount;

        if(amount < product.getCost()){
            cout<<"Insufficient Amount, please deposit additional "<<product.getCost() - amount<<"cents"<<endl;

            cin >>amountR;

            amount+=amountR;
        }
        if(amount >= product.getCost()){
            cout<<"Here is your Juice, enjoy"<<endl;
            counter.acceptAmount(amount);
            product.makeSale();
        }
        else{
            cout<<"Amount is not enough, collect what you deposited"<<endl;
        }

    }
    else
        cout<<"Sorry, out of stock for this juice"<<endl;
}

