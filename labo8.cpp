#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair {
	int start;
	int finish;
};

int actividadesRealizar(vector<Pair> &jobs)
{
	sort(jobs.begin(), jobs.end(),
		[](Pair &x, Pair &y) {
			return x.start < y.start;
		});

	vector<int> L(jobs.size());

	for (int i = 0; i < jobs.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (jobs[j].finish < jobs[i].start && L[i] < L[j])
			{
				L[i] = L[j];
			}
		}
		L[i]++;
	}

	return *max_element(L.begin(), L.end());
}

int main()
{
	vector<Pair> jobs =
	{
    //Pares ordenados con su respectivo inicio y fin (inicio, fin)
		{0, 6}, {1, 4}, {2, 13}, {3, 5}, {3, 8}, {5, 7},
		{5, 9}, {6, 10}, {8, 11}, {8, 12}, {12, 14}
	};

	cout << "Actividades que pueden realizarse: "
		 <<actividadesRealizar(jobs);

	return 0;
}
