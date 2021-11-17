#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
using namespace std;


int main()
{
	// задание 1

	// состояние гонки

	//long count = 0;

	//thread thr1([&]()
	// {
	// for (auto i = 0; i < 1000000; ++i)
	// {
	// ++count;
	// }
	// });
	//thread thr2([&]()
	// {
	// for (auto i = 0; i < 1000000; ++i)
	// {
	// ++count;
	// }
	// });

	//thr1.join();
	//thr2.join();

	//cout << count;
	//return 0;

	// устранение состояния гонки

	//long count = 0;
	//mutex count_mutex;

	//thread thr1([&]()
	// {
	// for (auto i = 0; i < 1000000; ++i)
	// {
	// count_mutex.lock();
	// ++count;
	// count_mutex.unlock();
	// }
	// });
	//thread thr2([&]()
	// {
	// for (auto i = 0; i < 1000000; ++i)
	// {
	// count_mutex.lock();
	// ++count;
	// count_mutex.unlock();
	// }
	// });

	//thr1.join();
	//thr2.join();

	//cout << count;
	//return 0;

	//задание 2

	int arr[5] = { 8, 10, 2, 4, 6 };
	mutex arr_mutex;

	thread bubblesort([&]()
	{
		for (auto i = 0; i < 5; i++)
		{
			arr_mutex.lock();
			int tmp = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = (5 - 1); j >= (i + 1); j--)
				{
					if (arr[j] < arr[j - 1]) {
						tmp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = tmp;
					}
				}
			}
			cout << "\nBubble sort " << i + 1 << " element: " << arr[i] << " ";
			arr_mutex.unlock();
		}
		cout << "\n";
	});

	thread selectsort([&]()
	{
		int v = 0;
		int tmp = 0;
		for (int i = 0; i < 5; i++)
		{
			arr_mutex.lock();
			v = i;
			for (int k = i; k < 5; k++)
			{
				if (arr[v] > arr[k])
				{
					v = k;
				}
			}
			tmp = arr[i];
			arr[i] = arr[v];
			arr[v] = tmp;
			cout << "\nSelect sort " << i + 1 << " element: " << arr[i] << " ";
			arr_mutex.unlock();
		}
		cout << "\n";
	});

	thread insertsort([&]()
	{
		int key = 0;
		int i = 0;
		for (int j = 0; j < 5; j++) {
			arr_mutex.lock();
			key = arr[j];
			i = j - 1;
			while (i >= 0 && arr[i] > key) {
				arr[i + 1] = arr[i];
				i = i - 1;
				arr[i + 1] = key;
			}
			cout << "\nInsertion sort " << j + 1 << " element: " << arr[j] << " ";
			arr_mutex.unlock();
		}
	});

	bubblesort.join();
	selectsort.join();
	insertsort.join();

	return 0;

}