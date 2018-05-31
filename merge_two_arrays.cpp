#include <iostream>

using namespace std;

//Function declarations  
int *merge (int array_a[], int size_a, int array_b[], int size_b);
void print_array (int *array_c, int size_of_c, string title);

int main()
{
	int array_a[5] = {5, 6, 7, 8, 9};
	int array_b[8] = {2, 7, 8, 16, 14, 25, 31, 39};
	
	int *array_c;

	int size_array_a = sizeof(array_a) / sizeof(array_a[0]);        // number of elements is array_a
	int size_array_b = sizeof(array_b) / sizeof(array_b[0]);		// number of elements is array_b

	array_c = merge (array_a, size_array_a, array_b, size_array_b);
	print_array(array_a, size_array_a, "Array A");
	print_array(array_b, size_array_b, "Array B");
	print_array(array_c, size_array_a + size_array_b, "Merged Array");
}

//#####################################################################  
// int *merge (int array_a[], int size_a, int array_b[], int size_b)
// Purpose: merges 2 arrays into a new array, in ascending order
// Pre-conditions: both input arrays are already sorted in ascending 
// order and have at least 1 element
// Post-conditions: returns array_c which contains all of the elements 
// from array_a and array_b, sorted in ascending order
//######################################################################  

int *merge (int array_a[], int size_a, int array_b[], int size_b)
{
	static int array_c[1];
	
	int a_counter = 0, b_counter = 0, end_counter = 0;	
	
	for (int i = 0; i < (size_a + size_b); i++)                     // add elements to array_c until i is less than the array_a + array_b 
	{
		bool at_end_array_a = (a_counter >= size_a);				// true when at end of array_a
		bool at_end_array_b = (b_counter >= size_b);				// true when at end of array_b
		
		if ( at_end_array_a == false && at_end_array_b == false )   // if not at end of array_a and array_b
		{
			if ( array_a[a_counter] < array_b[b_counter]  )         // check the current element of array_a and array_b based on their respective counters and add the element from array_a to array_c if its smaller
				{
				array_c[i] = array_a[a_counter];
				a_counter++;
				}
			else if ( array_a[a_counter] > array_b[b_counter] )     // check the current element of array_a and array_b based on their respective counters and add the element from array_b to array_c if its smaller
				{
				array_c[i] = array_b[b_counter];
				b_counter++;
				}
			else 													// both arrays have the same element (e.g. 4 & 4) so add both to array_c
				{
				array_c[i] = array_a[a_counter];					
				array_c[i + 1] = array_b[b_counter];
				a_counter++;	
				b_counter++;
				i++;												// increment i by an additional 1 as we added both, equal values to array_c
				}
		}
		else 
		{
			if (at_end_array_a) 									// we are at end of array_a
				{
				array_c[i] = array_b[b_counter];					// add the remaining elements of array_b to array_c
				b_counter++;
				}
			else													// we are at end of array_b
				{
				array_c[i] = array_a[a_counter];					// add the remaining elements of array_a to array_c
				a_counter++;	
				}
		}
	}
	
	return array_c;
}

//#####################################################################  
// void print_array (int *array, int size_of_array, string title)
// Purpose: simply print the elements of an array
// Pre-conditions: array has at least one element
// Post-conditions: prints elements of array to standard output
//######################################################################  

void print_array (int *array, int size_of_array, string title)
{
	cout<<title<<": ";                                                     
	
	for (int i = 0; i < size_of_array; i++)
	{
	cout << *(array + i);
	
	if (i < (size_of_array - 1) )                                          // print a comma between each value until the next to last value
		cout << ", ";
	}
	
	cout<<"\n"<<"\n";			
}
