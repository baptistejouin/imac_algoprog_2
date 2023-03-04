#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow *w = nullptr;

void insertionSort(Array &toSort)
{
	Array &sorted = w->newArray(toSort.size());

	// insertion sort from toSort to sorted
	sorted[0] = toShort[0];

	for (size_t n = 1; n < toShort.size(); n++)
	{
		int isFound = false;

		for (m = 0; m < toShort.size(); m++)
		{
			if (sorted[m] > toShort[n])
			{
				sorted.insert(m, toShort[n]);
				isFound = true;
				break;
			}
		}

		if (!isFound)
		{
			sorted.insert(n, toShort[n])
		}
	}

	toSort = sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount = 15;					// number of elements to sort
	MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
	w = new TestMainWindow(insertionSort);	// window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
