#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

int main() {
    while (true) {
        std::string row[3];
        int i;
        int j;
        int countX=0;
        int countO=0;
        int countPoint=0;
        bool correct=true;
        bool petyaWon=false;
        bool vanyaWon=false;
        for (i=0;i<3;i++) {
            std::cout<<"Enter row "<<i+1<<" with 3 symbols ('X'(engl), 'O' (engl), '.' only) "<<": ";
            std::cin>>row[i];
        }

        for (i=0;i<3;i++) {
            for (j=0;j<3;j++) {

                    //check input data  
                if (row[i].length()!=3 || 
                    row[i][j]!='X' && row[i][j]!='O' && row[i][j]!='.' ||
                    std::cin.fail() || std::cin.peek()!='\n') {
                    std::cout<<"Input Error\n";
                    correct=false;
                    //check input data


                    // X and O and . counts
                } else {
                    if (row[i][j]=='X') {
                        countX++;
                    } else if (row[i][j]=='O') {
                        countO++;
                    } else {
                        countPoint++;
                    }
                }
                    // X and O and . counts
            }
        }

        //check  X and O counts
        if (countO>countX && correct) {
            std::cout<<"X<O - impossible\n";
            correct=false;
        }
        //check  X and O counts



        //check X Petya won
        if (row[0][0]=='X' && row[1][0]=='X' && row[2][0]=='X' || 
            row[0][1]=='X' && row[1][1]=='X' && row[2][1]=='X' || 
            row[0][2]=='X' && row[1][2]=='X' && row[2][2]=='X' || 
            
            row[0][0]=='X' && row[0][1]=='X' && row[0][2]=='X' || 
            row[1][0]=='X' && row[1][1]=='X' && row[1][2]=='X' || 
            row[2][0]=='X' && row[2][1]=='X' && row[2][2]=='X' || 
            
            
            row[0][0]=='X' && row[1][1]=='X' && row[2][2]=='X' || 
            
            row[0][2]=='X' && row[1][1]=='X' && row[2][0]=='X' 
            && correct) {
                petyaWon=true;
        }
        //check X Petya won

        //check O Vanya won
        if (row[0][0]=='O' && row[1][0]=='O' && row[2][0]=='O' || 
            row[0][1]=='O' && row[1][1]=='O' && row[2][1]=='O' || 
            row[0][2]=='O' && row[1][2]=='O' && row[2][2]=='O' || 
            
            row[0][0]=='O' && row[0][1]=='O' && row[0][2]=='O' || 
            row[1][0]=='O' && row[1][1]=='O' && row[1][2]=='O' || 
            row[2][0]=='O' && row[2][1]=='O' && row[2][2]=='O' || 
            
            
            row[0][0]=='O' && row[1][1]=='O' && row[2][2]=='O' || 
            
            row[0][2]=='O' && row[1][1]=='O' && row[2][0]=='O' 
            && correct) {
                vanyaWon=true;
        }
        //check O Vanya won


        std::cout<<countX<<"\n";
        std::cout<<countO<<"\n";
        std::cout<<countPoint<<"\n";


        //result
        if (petyaWon) {
            if (vanyaWon) {
                std::cout<<"Cannot be 2 winners\n";
            } else if (countX==countO+1) {
                std::cout<<"Petya Won\n";
            } else {
                std::cout<<"Petya would won but 'X' and 'O' amounts incorrect\n";
            }
        } else {
            if (vanyaWon) {
                if (countX==countO) {
                    std::cout<<"Vanya Won\n";
                } else {
                    std::cout<<"Vanya would won but 'X' and 'O' amounts incorrect\n";
                }
            } else if (correct) {
                if (countPoint>0) {
                    if (countX==countO) {
                        std::cout<<"Petya's move\n";
                    } else if (countX==countO+1) {
                        std::cout<<"Vanya's move\n";
                    } else {
                        std::cout<<"Incorrect 'X' and 'O' amounts\n";
                    }
                } else if (countX==countO+1) {
                    std::cout<<"Draw\n";
                } else {
                    std::cout<<"Incorrect 'X' and 'O' amounts\n";
                }
            } else {
                std::cout<<"Incorrect\n";
            }
        }
        //result
    }         
}

    
    

    


