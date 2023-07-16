#include "Matrix.h"

namespace SapperBL
{

	class Matrix
	{

	public:

		Matrix(int _rowSize, int _columnSize)
		{
#ifdef DEBUG
			cout << "Constructor:\t" << this << endl;
#endif // DEBUG

			rowSize = _rowSize;
			columnSize = _columnSize;

			data = new int* [rowSize];

#ifdef DEBUG
			cout << "Data:\t\t" << data << endl;
#endif // DEBUG

			for (int i = 0; i < rowSize; i++)
			{
				data[i] = new int[columnSize];
#ifdef DEBUG
				cout << "Data["<<i<< "]:\t" << data[i] << endl;
#endif // DEBUG
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

	};

}