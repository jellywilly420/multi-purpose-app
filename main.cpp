#include <iostream>
#include <cmath>
using namespace std;

// used to determine which application the user wants to use
int app;
// used to determine if the user wants to reuse the program
string again;

// function to calculate the are of the shape, arguements are the shape and its dimensions
// if the shape has one dimension, we pass the second one as any float value
float area(int shape, float dimension1, float dimension2){
	
	switch (shape){
		case 1:
			
			return 3.14159 * pow(dimension1, 2);
			break;

		case 2:
			
			return pow(dimension1, 2);
			break;

		case 3:
			
			return dimension1 * dimension2;
			break;
	}
	return 0;
}


// returns the minimum of n integars
// arguements are the array of integars and the size of the array/how many numbers
int minimum(int arr[], int m){
	int min;

// gives the variable min the value of the first index of the array
	min = arr[0];

// iterates over the indices of the array, each time checking if the current index is less
// than the current value of min, if it is, min takes the value of the index and so on
	for (int i = 0; i < m; i++){
		if (arr[i] < min){
			min = arr[i];
		}
	}

	return min;

}


void pattern(int rows){

// outer loop to go over each row
for (int row = 1; row <= rows; row++){
	// inner loop to go over every item in each row 
	for (int column = 1; column <= 2 * rows - 1; column++){
		  // prints out a blank space in every spot that meets the condition
		  if (column <= rows - row || column >= rows + row){
			cout << " ";
		  }
		  else{
		    cout << "*";
		  }
	}
	// starts a new line after each row is completely filled in
	cout << "\n";
}
}



int main(){

	// prompts the use to select an application, answer is stored in the app variable
	cout << "Please, select one of the following applications:\n";
	cout << "	[1] Select 1 to calculate area\n";
	cout << "	[2] Select 2 to excute comparator\n";
	cout << "	[3] Select 3 to excute summing system\n";
	cout << "	[4] Select 4 to find minimum of n numbers\n";
	cout << "	[5] Select 5 to print pattern on the screen\n";
	cout << "Please, enter your selection: \n";

	cin >> app;
	cout << "\n\n\n";

	// runs the code for the app that the user picked 
	switch (app){
		// area calculation
		case 1:
			// stores the shape
			int sel;
			// store the dimensions of the shape(s)
			float radius, side, height, width;

			cout << "What shape do you want to calculate the area of?\n";
			cout << "1)Circle\n2)Square\n3)Rectangle\n";

			cin >> sel;

			// calls area() for the shape that the user picked
			switch (sel){
				case 1:
					cout << "Please insert the radius of the circle: ";
					cin >> radius;

					cout << "Area = " << area(1, radius, 0) << " square units";
					break;
			
				case 2:
					cout << "Please insert the length of the square's side: ";
					cin >> side;

					cout << "Area = " << area(2, side, 0) << " square units";
					break;
			
				case 3:
					cout << "Please insert the height of the rectangle: ";
					cin >> height;
					cout << "Please insert the length of the rectangle: ";
					cin >> width;

					cout << "Area = " << area(3, height, width) << " square units";
					break;
			}
			break;

		// comparator system
		case 2:
			// for storing the integar values
			int x, y, z;
			// prompts the user to input the values
			cout << "Please insert the 1st integar: ";
			cin >> x;
			cout << "Please insert the 2nd integar: ";
			cin >> y;
			cout << "Please insert the 3rd integar: ";
			cin >> z;

			// compares the 3 variables and prints out the greatest of them
			if (x >= y && x >= z){
				cout << "Largest integar is " << x << ".\n";
			}
			else if (y >= x && y >= z){
				cout << "Largest integar is " << y << ".\n";
			}
			else{
				cout << "Largest integar is " << z << ".\n";
			}
			break;

		// summing system
		case 3:
			// stores the number of values
			int n;
			// an array for storing the values and 2 variables for storing the output
			float nums[9999], average, sum;
			sum = 0;

			cout << "Please insert how many numbers you want the average and sum of: ";
			cin >> n;

			// asks for input and stores each value in the array nums[]
			// every value entered is added to the value of sum
			for (int i = 0; i < n; i++){
				cout << i + 1 << ". Insert number: ";
		        cin >> nums[i];
		        sum += nums[i];
			}
			// calculates the average
			average = sum / n;
			// prints out the output
			cout << "Average = " << average << "\n";
			cout << "Sum = " << sum << "\n";
			break;

		// minimum of n numbers
		case 4:
			// m stores the number of values and arr[] stores the values themselves
			// m doubles as the size of arr[]
			int m, arr[9999];

			cout << "Please insert how many numbers you want the minimum of: ";
			cin >> m;
			// gets input and stores it in arr[]
			for (int i = 0; i < m; i++){
				cout << i + 1 << ". Insert number: ";
				cin >> arr[i];
			}
			cout << "The minimum is " << minimum(arr, m);

			break;

		// drawing a pattern
		case 5:
			int rows;
			cout << "Enter the number of rows: \n";
			cin >> rows;

			pattern(rows);
			break;
	}

	// looping system
	cout << "\n\nWould you like to use the program again? (yes/no)\n";
	cin >> again;
	// if the conditions are met, the program restarts using recursion
	// if not, it ends
	if (again == "yes" || again == "Yes" || again == "YES"){
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		main();
	}
	else{
		return 0;
	}
}
