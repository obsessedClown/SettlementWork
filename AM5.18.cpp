#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string filename;
	cout << "Введите имя файла: \n";
	cin >> filename;
	vector<vector<int>> a;
	ifstream stream(filename);
	string tempLine;
	string tempChar;
	getline(stream, tempLine);
	int n;
	n = stoi(tempLine);
	while (getline(stream, tempLine))
	{
		stringstream s_stream(tempLine);
		vector<int> vec_h;
		while (getline(s_stream, tempChar, ' ')) {
			vec_h.push_back(stoi(tempChar));
		}
		a.push_back(vec_h);
	}
	stream.close();

	const int INF = 1000000000;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -a[i][j];
			if (a[i][j] == 0 && i != j)
			{
				a[i][j] = INF;
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	cout << "Введите вершины, между которыми нужно найти максимальный путь: \n";
	int v1, v2;
	cin >> v1 >> v2;
	cout << "Максимальный путь между вершинами " << v1 << " и " << v2 << " равен: " << abs(a[v1 - 1][v2 - 1]);
}