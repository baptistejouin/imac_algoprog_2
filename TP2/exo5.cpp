#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow *w = nullptr;

void merge(Array &first, Array &second, Array &result);

void splitAndMerge(Array &origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if (origin.size() <= 1)
		return;

	// initialisation
	Array &first = w->newArray(origin.size() / 2);
	Array &second = w->newArray(origin.size() - first.size());

	// split
	for (size_t i = 0; i < first.size(); i++)
	{
		first.insert(i, origin.get(i));
	}

	for (size_t i = 0; i < second.size(); i++)
	{
		second.insert(i, origin.get(first.size() + i));
	}

	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);

	// merge
	merge(first, second, origin);
}

void merge(Array &first, Array &second, Array &result)
{
	int i = 0, j = 0;

	while (i < first.size() || j < second.size())
	{
		if (i == first.size())
		{
			result.insert(i + j, second.get(j));
			j++;
		}
		else if (j == second.size())
		{
			result.insert(i + j, first.get(i));
			i++;
		}
		else
		{
			if (first.get(i) < second.get(j))
			{
				result.insert(i + j, first.get(i));
				i++;
			}
			else
			{
				result.insert(i + j, second.get(j));
				j++;
			}
		}
	}
}

void mergeSort(Array &toSort)
{
	splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
	w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
