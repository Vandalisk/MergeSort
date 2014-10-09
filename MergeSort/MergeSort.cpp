// MergeSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Merge(int *a, int l, int split, int r){
	int pos1 = l;
	int pos2 = split + 1;
	int i;

	int *b = new int [ r - l + 1];
	for(i = 0; i < r - l + 1; i++)
		b[i] = 0;
	i = 0;
	while(pos1 <= split && pos2 <= r){
		if(a[pos1] > a[pos2]){
			b[i] = a[pos2];
			i++; pos2++;
		}
		else{
			b[i] = a[pos1];
			i++; pos1++;
		}
	}	
	while(pos1 <= split){
		b[i] = a[pos1];
		i++; pos1++;
	}
	while(pos2 <= r){
		b[i] = a[pos2];
		i++; pos2++;
	}	
	
	for( int i = 0; i < r - l + 1; i++)
		a[l + i] = b[i];
	delete(b);
}
void MergeSort(int *a, int l, int r){
	int split = (l + r) / 2;
	if(l < r){		
		MergeSort(a, l, split);       // сортировать левую половину
		MergeSort(a, split+1, r);// сортировать правую половину		
	}
	Merge(a, l, split, r);    // слить результаты в общий массив
}

int main()
{
	setlocale(LC_ALL,"Rus");
	int n;
	int *result;
	cin >> n;	
	int *a = new int [n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	MergeSort(a, 0, n);
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}




