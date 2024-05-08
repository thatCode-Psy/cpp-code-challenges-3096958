// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool sort_array(int *arr, int n){

    if(n <= 1) 
    {
        return true;
    }
    int node = arr[0];
    int node_pos = 0;
    for(int i = 1; i < n; ++i){
        if (arr[i] < node) {
            int temp = arr[i];
            for (int j = i; j > node_pos; --j){
                arr[j] = arr[j-1];
            }
            arr[node_pos] = temp;
            node_pos++;
        }
    }
    sort_array(arr, node_pos);
    if (node_pos + 1 < n) {
        int* second_arr = &arr[node_pos + 1];
        sort_array(second_arr, n - (node_pos + 1));
    }
    
    return true;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
