#include <iostream>
using namespace std;



class car
{
	public:
		car();
		~car();

		bool moveForward(int carVisual[][6]);
		bool moveBackward(int carVisual[][6]);
		bool didWeWin();

		void setSize(const int newSize);
		int getSize() const;

		void setOrientation(const char newOrientation);
		char getOrientation() const;

		void setRow(const int newRow);
		int getRow() const;

		void setColumn(const int newColumn);
		int getColumn() const;



	private:
		int size;
		char orientation;
		int row;
		int column;




};

/**
@brief  This is the constructor for the ADT, sets all values to NULL or 0


*/

car::car()
{
	size = 0;
	orientation = '\0';
	row = 0;
	column = 0;
}

/**
@brief This is the constructor for the ADT.


*/
car::~car()
{

}

/**
@brief This is the function that moves a car ADT on the grid
@pre carVisual sent in, car does not exceed bounds
@post moved car or return
@return false or true based on whether the car can move

*/

bool car::moveForward(int carVisual[][6])
{
	/*
		cout << "Orientation: " << orientation << "2nd condition:  " << carVisual[row][column+1] << endl;
		*/
		if(orientation == 'H' && column + size < 6)
		{
			if(carVisual[row][column+size] == 1)
			{
				return false;
			}
			else
			{

				carVisual[row][column] = 0;
				carVisual[row][column+size] = 1;

				column += 1;

				for(int i = 0; i < 6; i++)
				{
					for(int j = 0; j < 6; j++)
					{
						cout << carVisual[i][j];
					}
					cout << endl;

						//DEBUG
				}
				cout << endl;


				return true;
			}


			//DEBUG

		}

		if(orientation == 'V' && row + size < 6)
		{

			if(carVisual[row+size][column] == 1)
			{
				return false;
			}
			else
			{
				carVisual[row][column] = 0;
				carVisual[row+size][column] = 1;
				row += 1;

				for(int i = 0; i < 6; i++)
				{
					for(int j = 0; j < 6; j++)
					{
						cout << carVisual[i][j];
					}
					cout << endl;

						//DEBUG
				}
				cout << endl;


				return true;
			}


			//DEBUG





		}


		return false;

	//DEBUG

	cout << "Going forward!:  " << endl;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << carVisual[i][j];
		}
		cout << endl;

			//DEBUG
	}

	cout << endl;

	return false;

}

/**
@brief This is the function that moves a car ADT on the grid
@pre carVisual sent in, car does not exceed bounds
@post moved car or return
@return false or true based on whether the car can move

*/

bool car::moveBackward(int carVisual[][6])
{

		if(orientation == 'H' && column != 0)
		{

		 if(carVisual[row][column - 1] == 0)
			{

				carVisual[row][column+size-1] = 0;
				carVisual[row][--column] = 1;


					cout << "Going Backward!" << endl;
					for(int i = 0; i < 6; i++)
					{
						for(int j = 0; j < 6; j++)
						{
							cout << carVisual[i][j];
						}
						cout << endl;
					}
					cout << endl;



				return true;
			}

		}





		if(orientation == 'V' && row != 0)
		{

			if(carVisual[row - 1][column] == 0)
			{

				carVisual[row+size-1][column] = 0;
				carVisual[--row][column] = 1;


					cout << "Going Backward!" << endl;
					for(int i = 0; i < 6; i++)
					{
						for(int j = 0; j < 6; j++)
						{
							cout << carVisual[i][j];
						}
						cout << endl;
					}
					cout << endl;



				return true;
			}
		}



		/*
			cout << "Going Backward!" << endl;
			for(int i = 0; i < 6; i++)
			{
				for(int j = 0; j < 6; j++)
				{
					cout << carVisual[i][j];
				}
				cout << endl;
			}
			cout << endl;
			*/

	return false;
	}

/**
@brief This function checks whether or not we have won the game
@return true or false
*/

bool car::didWeWin()
{
	if(column + 1 == 5)
		return true;
	return false;
}

/**
@brief  sets the 'size' variable
@pre newSize custom int input
@post size = newSize
*/

void car::setSize(const int newSize)
{
	size = newSize;
}

/**
@brief  gets the 'size variable'
*/

int car::getSize() const
{
	return size;
}

/**
@brief  sets the 'orientation' variable
@pre newOrientation custom char input
@post orientation = newOrientation
*/

void car::setOrientation(const char newOrientation)
{
	orientation = newOrientation;
}

/**
@brief gets the 'orientation' variable
*/

char car::getOrientation() const
{
	return orientation;
}

/**
@brief sets the 'row' variable
@pre newRow custom int input
@post row = newRow
*/
void car::setRow(const int newRow)
{
	row = newRow;
}


/**
@brief gets the 'row' variable
*/

int car::getRow() const
{
	return row;
}

/**
@brief sets the 'column' variable
@pre newColumn custom int input
@post column = newColumn
*/

void car::setColumn(const int newColumn){
	column = newColumn;
}

/**
@brief gets the column variable
*/

int car::getColumn() const
{
	return column;
}

/**
@brief  This is the recursive function to solve the number of moves for this problem
@pre carVisual, moves, #cars, cap, best, and carsArray sent in
@post base case will determine stopping points
@return void
*/

void solveIt(int moves, int carVisual[][6], int numCars, int& cap, int& best, car carsArray[]);


int main()
{
	int numCars = 0;

	int size = 0;
	char orientation = '\0';
	int row = 0;
	int column = 0;
	bool main = 0;

	int cap = 10;
	int best = 11;
	int moves = 0;
	int iterations = 0;


	int carVisual[6][6] = {0};
	car carsArray[100];


	cin >> numCars;



	while(numCars != 0)
	{

		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				carVisual[i][j] = 0;
			}
		}
		size = 0;
		orientation = '\0';
		row = 0;
		column = 0;
		main = 0;
		cap = 10;
		best = 11;
		moves = 0;



		iterations++;

				for(int i = 0; i < numCars; i++)
				{
					cin >> size;
					cin >> orientation;
					cin >> row;
					cin >> column;

					carsArray[i].setSize(size);
					carsArray[i].setOrientation(orientation);
					carsArray[i].setRow(row);
					carsArray[i].setColumn(column);

					int tempColumn = carsArray[i].getColumn();
					int tempRow = carsArray[i].getRow();

					//cout << tempRow << " ";
					//cout << tempColumn << ":  " << carsArray[i].getSize() << carsArray[i].getOrientation() << endl;

					if(orientation == 'H')
					{
						if(carsArray[i].getSize() == 2)
						{
							carVisual[tempRow][tempColumn] = 1;
							carVisual[tempRow][tempColumn+1] = 1;
						}
						else
						{
							carVisual[tempRow][tempColumn] = 1;
							carVisual[tempRow][tempColumn+1] = 1;
							carVisual[tempRow][tempColumn+2] = 1;
						}
					}
					else if (orientation == 'V')
					{
						if(carsArray[i].getSize() == 2)
						{
							carVisual[tempRow][tempColumn] = 1;
							carVisual[tempRow+1][tempColumn] = 1;
						}
						else
						{
							carVisual[tempRow][tempColumn] = 1;
							carVisual[tempRow+1][tempColumn] = 1;
							carVisual[tempRow+2][tempColumn] = 1;
						}
					}


				}


		solveIt(moves, carVisual, numCars, cap, best, carsArray);

			cout << "Scenario " << iterations <<" requires " << best << " moves" << endl;

			cin >> numCars;


	}


/*
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << carVisual[i][j];
		}
		cout << endl;
	}
*/




return 0;
}


void solveIt(int moves, int carVisual[][6], int numCars, int& cap, int& best, car carsArray[])
{
	if(carsArray[0].didWeWin())
	{

		if(moves < best)
		{
			best = moves;
			cap = best;

			return;
		}
	}
	if(moves > cap)
	{
		moves = cap;
			return;
	}


	for(int i = 0; i < numCars; i++)
	{
		/*
		cout << "CARS:  " << numCars;
		cout << "CAR DATA:  " << carsArray[i].getRow() << " " << carsArray[i].getColumn() << " " << carsArray[i].getSize() << endl;
		*/
		if(carsArray[i].moveForward(carVisual))
		{
			solveIt(moves+1, carVisual, numCars, cap, best, carsArray);
			carsArray[i].moveBackward(carVisual);
		}
		if(carsArray[i].moveBackward(carVisual))
		{
			solveIt(moves+1, carVisual, numCars, cap, best, carsArray);
			carsArray[i].moveForward(carVisual);
		}

	}

	return;
}
