// C++ Code Challenges, LinkedIn Learning

// Challenge #15: JSON File Validation
// Write an application that reads a JSON file and checks if it's valid or not.
// Test the bracket balance (curly and square), and quote balance. 
// Assume simple content with no escape characters inside strings.
// The application outputs a message indicating if the JSON file passed the tests or not.


#include <iostream>
#include <fstream>
#include <string>

// JSON File Validation, main()
// Summary: This application checks the balance of braces, brackets, and quotes in a JSON file.
 
int main(){
    
    std::string line;
    int braces=0, brackets=0, quotes=0;
    
    std::fstream file ("jason.json", std::ios::in);
    if(file.is_open()){
        while(std::getline(file, line)){
            for (auto &ch : line){
                if(quotes==0)
                    switch(ch){
                        case '{':
                            braces++;
                            break;
                        case '}':
                            braces--;
                            break;
                        case '[':
                            brackets++;
                            break;
                        case ']':
                            brackets--;
                            break;
                        case '"':
                            quotes++;
                            break;
                    }             
                else
                    if(ch=='"')
                        quotes--;

                if(braces<0 || brackets<0)
                    braces = -1000000;
            }
        }
    }
    else{
        std::cout << "Something went wrong\n";
        return 1;
    }
    if(brackets==0 && braces==0 && quotes==0)
        std::cout << "The file is valid!\n\n";
    else
        std::cout << "The file is invalid!\n\n";
    return 0;
}
 