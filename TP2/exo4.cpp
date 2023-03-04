#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow *w = nullptr;

void recursivQuickSort(Array &toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if (size <= 1)
		return;

	Array &lowerArray = w->newArray(size);
	Array &greaterArray = w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes
	int pivot = (size - 1) / 2;			// on divise le tableau en deux par la valeur du centre

	int pValue = toSort.get(pivot);

	// split
	for (size_t i = 0; i < size; i++)
	{
		if (pivot != i)
		{
			if (toSort[i] < pValue)
			{
				lowerArray.insert(lowerSize, toSort.get(i));
				lowerSize++;
			}
			else
			{
				greaterArray.insert(greaterSize, toSort.get(i));
				greaterSize++;
			}
		}
	}

	// recursiv sort of lowerArray and greaterArray
	recursivQuickSort(lowerArray, lowerSize);
	recursivQuickSort(greaterArray, greaterSize);

	// merge

	for (size_t i = 0; i < lowerSize; i++)
	{
		toSort.insert(i, lowerArray.get(i));
	}

	toSort.insert(lowerSize, pValue);

	for (size_t i = 0; i < greaterSize; i++)
	{
		toSort.insert(i + lowerSize + 1, greaterArray.get(i));
	}
}

void quickSort(Array &toSort)
{
	recursivQuickSort(toSort, toSort.size());
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount = 20;
	MainWindow::instruction_duration = 50;
	w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
