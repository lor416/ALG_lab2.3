
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct tree {
	tree* left = NULL;
	tree* right = NULL;
	int info;
	bool ind = true;
	void add(int x) {
		if (ind == true) {
			ind = false;
			info = x;
		}
		else if (x > info) {
			if (right == NULL) 
				right = new tree;
			right->add(x);
		}
		else if (x < info) {
			if (left == NULL) 
				left = new tree;
			left->add(x);
		}
	}
};
void PrLeftObxod(tree* dr, ofstream &fout){
	if (dr != 0){
		fout << dr->info << endl;
		PrLeftObxod(dr->left, fout);
		PrLeftObxod(dr->right, fout);
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	tree drevo;
	int x;
	while (fin >> x) {
		cout << x;
		drevo.add(x);
	}
	PrLeftObxod(&drevo, fout);
	fin.close();
	fout.close();
}