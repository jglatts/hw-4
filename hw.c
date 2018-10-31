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
	int grade_size, grades;

	printf("\n=================================\n");
	printf("How Many Grades Are You Entering?");
	printf("\n=================================\n --> ");
	scanf("%d", &grade_size);

	int grade_array[grade_size];  //initiize the array with user input  

	for (int i = 0; i < grade_size; ++i)
	{
		printf("\nEnter Grade\n");
		printf("Enter -1 To Exit\n--> ");
		scanf("%d", &grades);   //can is stay as one variable? REFRACTOR
		if (grades != -1)
		{
			grade_array[i] = grades;
		}
		else
		{
			// show the report if the user quits early
			return 1; 
		}
	}

	sort_grades(grade_array, grade_size);

	for (int g = 0; g < grade_size; ++g)
	{
		printf("\n%d\n", grade_array[g]);
	}

	return 0;
}


/* Sort the grades in the array using Bubble Sort */
void sort_grades(int array_grades[], int size)
{

	int lowest_index = 0, temp, i;

	for (i = 0; i <= size - 2; ++i)  // loop through whole list
	{
		for (int j = 1; j < size; ++j)	
		{
			if (array_grades[j] < array_grades[lowest_index])
			{
				lowest_index = j;
			}
		}
	}
	// start swapping
	temp = array_grades[i];
	array_grades[i] = array_grades[lowest_index];
	array_grades[lowest_index] = temp;
	lowest_index = i + 1;

}
