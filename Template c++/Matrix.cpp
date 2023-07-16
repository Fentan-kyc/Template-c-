#include "Matrix.h"

namespace SapperBL
{

	class Matrix
	{

	public:
		int GetRowSize() { return rowSize; };
		int GetColumnSize() { return rowSize; };

		Matrix(int _rowSize, int _columnSize)
		{

			rowSize = _rowSize;
			columnSize = _columnSize;

			CreateDataStructure(data);
			InitializeDataRand(data, rand);
		}

		Matrix(const Matrix& other)
		{
			rowSize = other.rowSize;
			columnSize = other.columnSize;

			data = new int* [rowSize];

			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++)
				{

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

	private:
		int rowSize;
		int columnSize;

		int** data;

		void CreateDataStructure(int** data)
		{
			data = new int* [rowSize];

			for (int i = 0; i < rowSize; i++)
			{
				data[i] = new int[columnSize];
		}
		}
		void InitializeDataRand(int** data, int(generateNumber)())
		{
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < columnSize; j++) 
				{
					data[i][j] = generateNumber();
					cout << data[i][j] << endl;
				}
			}
		}
	};

}