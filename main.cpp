#include <iostream>
#include<vector>
#include <string>
#include "Stack_advanced_ver.h"

using std::vector ;
using std::cout;
using std::string ;


vector<string> split(const string& expression) ;


int evaluate_expression(const string& expression) ;

void process_an_operator(
        Stack_advanced<int>& operand_stack, Stack_advanced<char>& operator_stack );



int main() {


    string expression ;
    cout<<"enter an word " << std::endl ;
    getline(std::cin,expression) ;

    cout<<"Expression" << " = " <<evaluate_expression(expression) << std::endl ;




    return 0;
}



int evaluate_expression(const string& expression){

    Stack_advanced<int> operand_stack ;
    Stack_advanced<char> operator_stack ;
    
    vector<string> tokens = split(expression) ;








    return 0 ;
}



vector<string> split(const string& expression){

    vector<string> vv ;
    string number_string ;

    for(unsigned i =0;i<expression.length(); i++){

        if(isdigit(expression[i]))
            number_string.append(1,expression[i]) ;

        else{

            if(number_string.size() > 0 ){

                vv.push_back(number_string) ;
                number_string.erase() ;

            }
            if(!isspace(expression[i])){

                string s  ;
                s.append(1,expression[i]) ;
                vv.push_back(s) ;


            }




        }




    }
    if(number_string.size() >0)
        vv.push_back(number_string) ;




    return  vv ;
}











