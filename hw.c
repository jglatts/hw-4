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
	int grade_size, grades, lowest_grade, highest_grade, grade_array[100], actual_grade_size = 0; // array has to be initilized after the "grade_size scanf". Windows CL issue 

	printf("\n=================================\n");
	printf("How Many Grades Are You Entering?");
	printf("\n=================================\n --> ");
	scanf("%d", &grade_size);

	  
	for (int i = 0; i < grade_size; ++i)
	{
		printf("\nEnter Grade\n");
		printf("Enter -1 To Exit\n--> ");
		scanf("%d", &grades);   //can is stay as one variable? REFRACTOR
		if (grades != -1)
		{
			grade_array[i] = grades;
			actual_grade_size++;
		}
		else
		{
			// show the report if the user quits early
			break; 
		}
	}

	sort_grades(grade_array, actual_grade_size);
	// this has to be it's own function; print_all_grades
	printf("\n=================================\n");
	printf("\tAll Grades");
	printf("\n=================================\n");
	for (int g = 0; g < actual_grade_size; ++g)
	{
		printf("\n%d\n", grade_array[g]);
	}

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

	return 0;
}


/* Sort the grades in the array using Bubble Sort */
void sort_grades(int array_grades[], int size)
{
  int i, d, temp;
 
  for (i = 0 ; i < size - 1; i++)
  {
    for (d = 0 ; d < size - i - 1; d++)
    {
      if (array_grades[d] > array_grades[d+1])
      {
        /* Swap Values */
        temp = array_grades[d];
        array_grades[d] = array_grades[d+1];
        array_grades[d+1] = temp;
      }
    }
  }
}


int get_lowest_grade(const int array_grades[], int size)
{
	return array_grades[0];  // array is already sorted, so first index is smallest
}


int get_highest_grade(const int array_grades[], int size)
{
	// does not return correct value if the user quits early 
	return array_grades[size];  // array is already sorted, so last index is largest
}
