#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <array>
using namespace std;
void print_rotated(vector<string> v, int depth, int index);
void print_not_rotated(vector<string> v);
int pow2(int n);
void print_htree(vector<string> v);
int center(int n);
int depth(int n);
void H(int node, int i, int j, int d, int U, int D, int R, int L, vector<string> v, string** H_tree);

int main(void)
{
	string com, ch;
	vector<string> v;
	while (1) {

		cin >> com;
		if (com == "EOI")
			break;

		else if (com == "INS")
		{
			cin >> ch;
			v.push_back(ch);
			push_heap(v.begin(), v.end());
		}
		else if (com == "DEL")
		{
			pop_heap(v.begin(), v.end());
			v.pop_back();
		}
	}


	cout << endl << endl;
	cout << "1. rotated form" << endl;
	cout << endl<< endl;
	print_rotated(v, 0, 0);
	cout << endl << endl;
	cout << "2. not-rotated form" << endl;
	cout << endl;
	print_not_rotated(v);
	cout << endl<< endl;
	cout << "3. H-tree form" << endl;
	print_htree(v);
	cout << endl;

}

void print_rotated(vector<string> v, int depth,int index)
{
	
	if (index < v.size())
	{
		int idx = index;
		print_rotated(v, depth + 1,2*index+2);
		cout << setw(2 * depth) << "" << v[index] << endl;
		print_rotated(v, depth + 1,2*index +1);
	}

}

void print_not_rotated(vector<string> v)
{
	int n = pow2(v.size());
	int idx = 0;
	for (int i = n; i>=0; i--) {
		
		cout << setw(pow(2, i));
		for (int j=0;j<pow(2,n-i);j++)
		{ 
			cout << v[idx]<<setw(pow(2,i+1));
			if (idx+1 == v.size())
				break;
			idx++;

		}
		cout << endl;
		
	}

}

void print_htree(vector<string> v) {
	int sizeX = v.size();
	int sizeY = v.size();
	string ** H_tree = new string*[sizeX];
	for (int i = 0; i < sizeY; ++i)
		H_tree[i] = new string[sizeY];

	
	H(1, center(v.size()), center(v.size()), depth(v.size()), 0, 1, 2, 3, v, H_tree);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (H_tree[i][j] == "")
				cout << " ";
			cout <<  H_tree[i][j];
		}
		cout << "\n";
	}
}
int center(int n) { return n <= 1 ? 0 : 2 * center(n / 4) + 1; }
int depth(int n) { return n <= 7 ? 1 : 2 * depth(n / 4); }

void H(int node, int i, int j, int d, int U, int D, int R, int L, vector<string> v, string** H_tree)
{
	int V[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	if (node > v.size()) return;

	 H_tree[i][j] = v[node - 1];
	if (2 * node <= v.size()) {
		H_tree[i + d * V[L][0]][j + d * V[L][1]] = v[2 * node - 1];
		H(4 * node, i + d * (V[L][0] + V[U][0]), j + d * (V[L][1] + V[U][1]), d / 2, D, U, L, R,v, H_tree);
		H(4 * node + 1, i + d * (V[L][0] + V[D][0]), j + d * (V[L][1] + V[D][1]), d / 2, U, D, R, L,v, H_tree);
	}
	if (2 * node + 1 <= v.size()) {
		H_tree[i + d * V[R][0]][j + d * V[R][1]] = v[2 * node];
		H(4 * node + 2, i + d * (V[R][0] + V[D][0]), j + d * (V[R][1] + V[D][1]), d / 2, U, D, R, L,v, H_tree);
		H(4 * node + 3, i + d * (V[R][0] + V[U][0]), j + d * (V[R][1] + V[U][1]), d / 2, D, U, L, R,v, H_tree);
	}
	
}



int pow2(int n)
{
	if ((pow(2, 0) <= n) && (n < pow(2, 1)))
	{
		return 0;
	}
	else if ((pow(2, 1) <= n) && (n < pow(2, 2)))
	{
		return 1;
	}
	else if ((pow(2, 2) <= n) && (n < pow(2, 3)))
	{
		return 2;
	}
	else if ((pow(2, 3) <= n)&&(n < pow(2,4)))
	{
		return 3;
	}
	else if ((pow(2, 4) <= n) && (n < pow(2, 5)))
	{
		return 4;
	}
	else if ((pow(2, 5) <= n) && (n < pow(2, 6)))
	{
		return 5;

	}
	else if ((pow(2, 6) <= n) && (n < pow(2, 7)))
	{
		return 6;
	}
	else return 0;

}

