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
	int grade_size, grades, grade_array[100]; // problem with windows combiler

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
		}
		else
		{
			// show the report if the user quits early
			return 1; 
		}
	}

	sort_grades(grade_array, grade_size);
	printf("\n=================================\n");
	printf("\tGrades Sorted!");
	printf("\n=================================\n");
	for (int g = 0; g < grade_size; ++g)
	{
		printf("\n%d\n", grade_array[g]);
	}

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
