/*
	
CIS 1057 Assignment 4
Due: 11/7/18
Author: John Glatts
Prof: Karl Morris

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Function Prototypes */
void sort_grades(int[], int);
void print_all_grades(const int[], int);
int get_lowest_grade(const int[], int);
int get_highest_grade(const int[], int);
double get_median_grade(const int[], int);
double get_mean_grade(const int[], int);


int main(int argc, char const *argv[])
{
	int grade_size, grades, lowest_grade, highest_grade, actual_grade_size = 0; // array has to be initilized after the "grade_size scanf". Windows CL issue 
	double median_grade, mean_grade;

	printf("\n=================================\n");
	printf("How Many Grades Are You Entering?");
	printf("\n=================================\n --> ");
	scanf("%d", &grade_size);
	int grade_array[grade_size];

	  
	for (int i = 0; i < grade_size; ++i)
	{
		printf("\nEnter Grade\n");
		printf("Enter -1 To Exit\n--> ");
		scanf("%d", &grades);
		if (grades != -1){
			grade_array[i] = grades;
			actual_grade_size++;
		}
		else {
			break; 
		}
	}

	sort_grades(grade_array, actual_grade_size);
	
	printf("\n=================================\n");
	printf("\tAll Grades");
	printf("\n=================================\n");
	print_all_grades(grade_array, actual_grade_size);

	printf("\n=================================\n");
	printf("\tLowest Grade");
	printf("\n=================================\n");
	lowest_grade = get_lowest_grade(grade_array, actual_grade_size);
	printf("%d", lowest_grade);

	printf("\n\n=================================\n");
	printf("\tHighest Grade");
	printf("\n=================================\n");
	highest_grade = get_highest_grade(grade_array, actual_grade_size);
	printf("%d", highest_grade);

	printf("\n\n=================================\n");
	printf("\tMedian Grade");
	printf("\n=================================\n");
	median_grade = get_median_grade(grade_array, actual_grade_size);
	printf("%.2f", median_grade);

	printf("\n\n=================================\n");
	printf("\tMean Grade");
	printf("\n=================================\n");
	mean_grade = get_mean_grade(grade_array, actual_grade_size);
	printf("%.2f\n", mean_grade);

	return 0;
}


/* Sort the grades in the array using Bubble Sort */
void sort_grades(int array_grades[], int size)
{
  int i, d, temp;
 
  for (i = 0 ; i < size - 1; i++){
    for (d = 0 ; d < size - i - 1; d++){
      //examine adjacent values, and swap if needed
      if (array_grades[d] > array_grades[d+1]){
        // swap values 
        temp = array_grades[d];
        array_grades[d] = array_grades[d+1];
        array_grades[d+1] = temp;
      	}
    }
  }
}


/* Print all grades in array */
void print_all_grades(const int array_grades[], int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%d\n", array_grades[i]);
	}
}


/* Return the lowest grade */
int get_lowest_grade(const int array_grades[], int size)
{
	return array_grades[0];  // array is already sorted, so first index is smallest
}


/* Return the highest grade */
int get_highest_grade(const int array_grades[], int size)
{
	return array_grades[size - 1];  // array is already sorted, so last index is largest
}


/* Return median grade as a double */
double get_median_grade(const int array_grades[], int size)
{
    double middle_number = 0;
	
    // check if array is even
    if(size % 2 == 0) {
        middle_number = (array_grades[(size - 1) / 2 ] + array_grades[size / 2]) / 2;
    }
    else {
        middle_number = array_grades[size / 2];
    }
	
    return middle_number;
}


/* Return mean grade as a double */
double get_mean_grade(const int array_grades[], int size)
{
	double count = 0, mean;

	for (int i = 0; i < size; ++i) {
		count = count + array_grades[i]; 
	}

	mean = count / size;

	return mean;  
}
