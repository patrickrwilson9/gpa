/*****************************************************************************
 *AUTHOR  	 : Patrick Wilson
 *PROJECT #	 : Selection & Repetition - GPA
 *DATE		 : 11/21/18
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/*****************************************************************************
 * Project : Selection & Repetition - GPA
 *----------------------------------------------------------------------------
 * This program obtains letter grades as input from a user, then converts each
 * 		letter grade into grade points.  This program runs a total of 3 times.
 *
 * The program should calculate and output the total grade points and the
 * 		grade point average.
 *----------------------------------------------------------------------------
 * INPUT:
 * One variable will be input:
 * 		Enter Letter grade # : grade (A,B,C,D,F)
 *
 * OUTPUT:
 * This program will output the total grade points and the grade point average.
 * 		Total Grade Points	 : totalGradePoints
 * 		GPA					 : gpa
 *
 *****************************************************************************/
int main()
{
	/*************************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * -----------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Titles of the Lab
	 *************************************************************************/

	const char PROGRAMMER[] = "Patrick Wilson";
	const int  LAB_NUM      = 1;
	const char LAB_NAME[]   = "Selection & Repetition - GPA";

	const int  TOTAL_TESTS  = 10;

	char grade;				// IN & OUT  - the letter grade earned
	int gradePoint;			// IN & CALC - letter grade converted to int value
	int gradeCount;			// In & CALC - the count # of grades recorded
	int CaseCount;			// IN & CALC - the count # of test cases (1 to 3)
	int totalGradePoints;   // IN & OUT  - the total grade points earned
	double gpa;				// IN & OUT  - the grade point average earned

	bool invalid;			// IN & CALC - condition for the error check


	//OUTPUT - Heading
	cout << left;
	cout << "**************************************************\n";
	cout << "*  PROGRAMMED BY : "  << PROGRAMMER << endl;
	cout << "*  PROJECT #" << setw(5)  << LAB_NUM    << ": " << LAB_NAME << endl;
	cout << setw(17) << "*  DATE"  << ": " << "11/21/18" << endl;
	cout << "**************************************************\n\n";
	cout << right;

	/*************************************************************************
	 * INPUT - read in one set of data:
	 * 		   grade
	 *************************************************************************/


	for (CaseCount = 1; CaseCount <= TOTAL_TESTS; CaseCount = CaseCount + 1)
	{
		cout << left;
		cout << "TEST CASE # " << CaseCount << ":"	<< endl;
		cout << right;

		gradeCount 		 = 1;
		totalGradePoints = 0;
		gpa		   	     = 0;

		do
		{
			// INPUT - grade
			cout << "Enter Letter Grade #" << gradeCount;
			cout << ": ";
			cin.get(grade);
			grade = toupper (grade);
			cin.ignore(10000,'\n');
			invalid = grade != 'A' && grade != 'B' && grade != 'C' &&
					  grade != 'D' && grade != 'F' && grade != 'X';
			if (invalid)
			{
				cout << "ERROR *** Please Enter a Valid Letter Grade\n";
			} // end if (invalid)

		} while (invalid);

			while (grade != 'X')
			{
				gradeCount = gradeCount + 1;

	/*************************************************************************
	 * PROCESSING - coverts grade to gradePoint, calculates totalGradePoints &
	 * 				gpa (grade point average).
	 *************************************************************************/

				switch(grade)
				{
					case 'A' : gradePoint = 4;
							   break;
					case 'B' : gradePoint = 3;
							   break;
					case 'C' : gradePoint = 2;
							   break;
					case 'D' : gradePoint = 1;
							   break;
					case 'F' : gradePoint = 0;
							   break;
				}// switch(grade)


			totalGradePoints = totalGradePoints + gradePoint;

				do
				{
					// INPUT - grade
					cout << "Enter Letter Grade #" << gradeCount;
					cout << ": ";
					cin.get(grade);
					grade = toupper (grade);
					cin.ignore(10000,'\n');
					invalid = grade != 'A' && grade != 'B' && grade != 'C' &&
							grade != 'D' && grade != 'F' && grade != 'X';
					if (invalid)
					{
						cout << "ERROR *** Please Enter a Valid Letter Grade\n";
					}// end if (invalid)

				} while (invalid);

			}// while (grade != 'X')


		gradeCount = gradeCount - 1;  // check if grade count = 0

			if (gradeCount != 0)
			{
				gpa = totalGradePoints / (double)gradeCount;

	/*************************************************************************
	* OUTPUT - totalGradePoints & gpa as follows:
	*
	* Total Grade Points: totalGradePoints
	* GPA: gpa
	*************************************************************************/

				// OUTPUT totalGradePoints & gpa
				cout << endl << "Total Grade Points: " << totalGradePoints;
				cout << endl << setprecision(2)  << fixed  << "GPA: "  << gpa;
				cout << endl << endl << endl;
				cout.unsetf(ios::fixed);
			}//if (gradeCount != 0)
		}//for (CaseCount = 1; CaseCount <= TOTAL_TESTS; CaseCount
		 // 									  = CaseCount + 1)

return 0;
}//main