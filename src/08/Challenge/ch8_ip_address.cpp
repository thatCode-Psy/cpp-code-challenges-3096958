// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    int count = 0;
    while(ip.compare("") != 0) {
        if(count >= 4){
            return false;
        }
        std::string check = ip;
        int decimal_loc = ip.find(".");
        if (decimal_loc == ip.length() - 1) { 
            return false;
        }
        if (decimal_loc != -1) {
            check = ip.substr(0, decimal_loc);
            ip = ip.substr(decimal_loc + 1, (ip.length() - decimal_loc) - 1);
        }
        else {
            ip = "";
        }
        int segment = std::stoi(check);
        if (segment < 0 || segment > 255)
        {
            return false;
        }
        ++count; 
    }
    return count == 4;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
