#include "main.h";

int main()
{
	Matrix matrix(20,20);

	Matrix matrix0(matrix);

	cout << matrix.GetNumberByPos(2, 1) << endl;
	cout << matrix0.GetNumberByPos(2, 1) << endl;

	system("pause");
	return 0;
}