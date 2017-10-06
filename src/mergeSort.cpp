#include <iostream>
#include <string>
#include <cstring>

/*
 * DUC LUU'S ALGORITHM IMPLEMENTAIONS
 *
 *  /\  |  _   _   _ o _|_ |_  o  _ _  _ 
 * /--\ | (_| (_) |  |  |_ | | | | | | > 
 *         _|                      
 *
 * MERGE SORT
 *
 * Overview:
 *   This algorithm is based on the classical divide-and-conquer paradigm. This works as follows:
 *   (1) Divide the n-element sequence to be sorted into two parts in the middle. Call it the left part 
 *       and right part.
 *           Example: input is  84 27 49 91 32 53 63 17
 *                     the left part will be: 84 27 49 91  
 *                     and the right part will be  32 53 63 17
 *   (2) Sort Each of them recursively using the mergesort.
 *            method. We already wrote function to sort it. Use the same.
 *   (3) Finally, merge the two sorted parts.
 *
 * Time Complexity
 *  + Best case    - O(n log(n))
 *  + Worst case   - O(n log n))
 *  + Average case - O(n log n))
 * 		
 * 
 * Space Complexity
 *  + O(n) auxiliary
 * ------------
 *
 * Referenced links:
 * 1. http://en.wikipedia.org/wiki/Merge_sort
 *
 * Notes: the insertion sort is actually a better sort than the merge sort if the original colleciton is almost sorted.
 * 
 */

template <typename T>
void merge(T * elements , unsigned int left_low, unsigned int left_high, unsigned int right_low, unsigned int right_high);

template <typename T>
void mergeSort(T * elements, unsigned int low, unsigned int high);

template <typename T>
void mergeSort(T * elements);

template <typename T>
void mergeSort(T * elements, unsigned int size) {
	mergeSort(elements, 0, size);
}

template <typename T>
void mergeSort(T * elements, unsigned int low, unsigned int high) {
	if (low < high) {
		unsigned int mid = (low + high) / 2; 
	
		mergeSort(elements, low, mid);
		mergeSort(elements, mid + 1, high );	
		merge(elements, low, mid, mid + 1, high);
	}
}

template <typename T>
void merge(T * elements, unsigned int left_low, unsigned int left_high, unsigned int right_low, unsigned int right_high) {
	unsigned int left = left_low;
	unsigned int right = right_low;
	int length = right_high - left_low + 1;
	
	T temp[length];
	
	for (unsigned int i = 0; i < length; i++) {
		if (left > left_high) {
			temp[i] = elements[right++];
		}
		else if (right > right_high) {
			temp[i] = elements[left++];
		}
		else if ((elements[left] - elements[right]) > 0) {
			temp[i] = elements[right++];
		}
		else 
			temp[i] = elements[left++];
	}
	
	for (unsigned int i = 0; i < length; i++) {
		elements[left_low++] = temp[i];
	}
}


int main() {
	// Test with char arrays
	char myword[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
		
	std::cout << "Original characters" << std::endl;
	for( int i = 0 ; i < strlen(myword) ; i ++ ){
		std::cout << myword[i]; 
	}
	
	std::cout << std::endl << "Call merged sort function" << std::endl;
	mergeSort <char> (&myword[0], strlen(myword) - 1);
	std::cout << "Sorted characters" << std::endl;
	
	for( int i = 0 ; i < strlen(myword) ; i ++ ){
		std::cout << myword[i]; 
	}
	
	// Test with integer arrays
	int numbers[] = {9, 1, 10, 4, 5, 0};
		
	std::cout << std::endl << "Original integers" << std::endl;
	
	for( int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i ++ ){
		std::cout << numbers[i] << " "; 
	}
		
	mergeSort <int> (&numbers[0], sizeof(numbers)/sizeof(numbers[0]) - 1);
	std::cout << std::endl << "Sort numbers" << std::endl;
	
	for( int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i ++ ){
		std::cout << numbers[i] << " "; 
	}
	std::cout << std::endl;

	return 0;
}
