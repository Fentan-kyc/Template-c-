#include "main.h";

int main()
{
	Matrix matrix(20,20);

	Matrix matrix0(matrix);

	matrix.ShowDebug();

	system("pause");
	return 0;
}