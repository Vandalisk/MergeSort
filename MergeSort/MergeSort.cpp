// MergeSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int * merge(int * mas1, int n, int * mas2, int m){
	int j = 0,k = 0,i = 0;
	int * res = new int [n + m];	
	while((j < n)&&(k < m)){
		if(mas1[j] < mas2[k]){
			res[i] = mas1[j]; j++;
		}
		else{
			res[i] = mas2[k]; k++;
		}
		i++;
	}
	while(j < n){
		res[i] = mas1[j];
		j++;
		i++;
	}
	while(k < m){
		res[i] = mas2[k];
		k++;
		i++;
	}
	return res;
}

int *sort(int l, int r, int *a){
	int  sered, n, m;
	int *first, *second;
	if(l == r){
		a[0] = l;
		return a;
	}
	else{
		if(r - l == 1){
			if(a[l] < a[r]){
				swap(a[l], a[r]);
				return a;
			}
			else return a;
		}
		else{
			sered = (l + r) / 2;
			n = sered - l + 1;
			m = r - sered;
			first = new int[n];
			second = new int[m];
			for( int i = 0; i < n; i++){
				first[i] = a[l + i];
			}
			for( int i = 0; i < m; i++){
				second[i] = a[sered + 1 + i];
			}
			return merge(sort(l, sered, first), n, sort(sered + 1, r, second), m);
		}
	}
}


int main()
{
	int n = 10,l = 0, r = n-1;
	int * a = new int[n];
	for( int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << endl;
	a = sort(l, r, a);
	for( int i = 0; i < n; i++){
		cout << a[i];
	}
}




