// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    
    // Write your code here
    if (v.size() < 4){
        return true;
    }
    int minima_index = 0;
    for (int i = 1; i < v.size(); ++i){
        if (v[i] < v[minima_index]) {
            minima_index = i;
        }
    }
    bool descending = false;
    int prev_index = minima_index;
    int current_index = minima_index + 1;
    if(current_index >= v.size()){
        current_index = 0;   
    }
    while(current_index != minima_index)
    {
        
        if(!descending && v[current_index] < v[prev_index]){
            descending = true;
        }
        if(descending && v[current_index] > v[prev_index]){
            return false;  
        }
        prev_index = current_index;
        current_index++;
        if(current_index >= v.size()){
            current_index = 0;   
        }
    }
    return (!descending) || v[current_index] <= v[prev_index] ;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    myvec = {1, 1, 1, 1, 1};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {3, 4, 5, 2, 2};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {3, 4, 5, 2, 4};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {1, 2, 3, 4, 5};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {1, 2, 3, 1, 2};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {5, 4, 6, 2, 6};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {5, 4, 3, 2, 1};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {5, 4, 3, 2, 6};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {5, 4, 6, 5, 4};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    myvec = {5, 4, 6, 5, 5};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.")<< std::endl;
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
