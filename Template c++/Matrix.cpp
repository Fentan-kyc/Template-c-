#include "Matrix.h"
#define DEBUG

namespace SapperBL
{
	typedef enum CellState {
		CELL_EMPTY,
		CELL_WITH_BOMB
	};

	class Matrix
	{

	public:
		int GetRowSize() { return rowSize; };
		int GetColumnSize() { return columnSize; };
		int GetNumberByPos(const int& row, const int& column) { return data[row][column]; };

		Matrix(int _rowSize, int _columnSize)
		{

			rowSize = _rowSize;
			columnSize = _columnSize;

			CreateDataStructure();
			InitializeDataEmpty();
		}

		Matrix(const Matrix& other)
		{
			rowSize = other.rowSize;
			columnSize = other.columnSize;

			int** otherData = other.data;
			this->CreateDataStructure();

			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++)
				{
					data[i][j] = otherData[i][j];
				}
			}
		}

		~Matrix()
		{
#ifdef DEBUG
			cout << "Deconstructor:\t" << this << endl;
#endif // DEBUG
			for (int i = 0; i < rowSize; i++)
			{
#ifdef DEBUG
				cout << "Deconstructor:\t" << data[i] << endl;
#endif // DEBUG
				delete[] data[i];
			}
#ifdef DEBUG
			cout << "Deconstructor:\t" << data << endl;
#endif // DEBUG

			delete[] data;
		}

		#ifdef DEBUG
		void ShowDebug() 
		{
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++)
				{
					cout << data[i][j] << "\t";
				}
				cout << endl;
			}
		}
		#endif // DEBUG

	private:
		int rowSize;
		int columnSize;

		int** data;

		void CreateDataStructure()
		{
			data = new int* [rowSize];

			for (int i = 0; i < rowSize; i++)
			{
				data[i] = new int[columnSize];
		}
		}

		/*void InitializeDataFunc(int(generateNumber)())
		{
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++) 
				{
					data[i][j] = generateNumber();
				}
			}
		}*/ //interest

		void  InitializeDataEmpty() 
		{
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++)
				{
					data[i][j] = (int)CELL_EMPTY;
				}
			}
		}

		void  InitializeDataRand() 
		{
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++)
				{
					data[i][j] = rand();
				}
			}
		}
	};

}