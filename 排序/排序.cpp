// 排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

//数组输出
void dispArray(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//直接插入排序
void directInsertionSort(int num[], int len)
{
	int *a = new int[len];
	int i, j, key;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	for (i = 1; i < len; i++)
	{
		if (a[i] < a[i - 1])
		{
			key = a[i];
			a[i] = a[i - 1];
			for (j = i - 1; key < a[j]; j--)
				a[j + 1] = a[j];
			a[j + 1] = key;
		}
	}
	dispArray(a, len);
}

//希尔排序
void shellSort(int num[], int len)
{
	int *a = new int[len];
	int i, j, key;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	key = len;
	do
	{
		key = key / 3 + 1;
		for (i = key; i < len; i++)
		{
			if (a[i] > a[i - key])
			{
				int temp = a[i];
				for (j = i - key; j >= 0 && temp > a[j]; j = j - key)
					a[j + key] = a[j];
				a[j + key] = temp;
			}
		}
	} while (key > 1);
	dispArray(a, len);
 }

//冒泡排序
void bubbleSort(int num[], int len)
{
	int *a = new int[len];
	int i, j, m, key;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	m = len-1;
	key = 1;
	while (m >= 0 && key == 1)
	{
		key = 0;
		for (j = 0; j < m; j++)
		{
			if (a[j] > a[j + 1])
			{
				key = 1; 
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		m--;
	}
	dispArray(a, len);
}

//快速排序
void quickSort(int a[], int low, int len)
{
	int i, j, m;
	if (low < len)
	{
		i = low;
		j = len;
		m = a[low];
		while (i < j)
		{
			while (i < j&&a[j] < m)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j&&a[i] >= m)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = m;
		quickSort(a, low,i-1);
		quickSort(a, i+1,len);
	}
}

//堆排序
void Adjust(int a[], int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIndex = index;   // a[left]、a[right]和a[maxIndex]三个数中最大数的下标
	if (left<len&&a[left]>a[maxIndex]) maxIndex = left;
	if (right<len&&a[right]>a[maxIndex]) maxIndex = right;
	if (maxIndex != index)  // 如果 maxIndex 有更新
	{
		swap(a[maxIndex], a[index]);
		Adjust(a, len, maxIndex);  // 递归调整其他不满足堆性质的部分
	}
}
void heapSort(int num[], int len)
{
	int *a = new int[len];
	int i, j;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	for (i = len / 2 - 1; i >= 0; i--)  //对每一个非叶子节点进行堆调整（从最后一个开始）
	{
		Adjust(a, len, i);
	}
	for (j = len - 1; j >= 1; j--)
	{
		swap(a[0], a[j]); // 将当前最大的放置到数组末尾
		Adjust(a, j, 0); // 将未完成排序的部分继续进行堆排序
	}
	dispArray(a, len);
}

//选择排序
void selectSort(int num[], int len)
{
	int *a = new int[len];
	int i, j;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	for (i = 0; i < len; i++)
	{
		int k = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < a[k]) k = j;
		}
		if (k != i)
		{
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	dispArray(a, len);
}

int main()
{
	int num[] = { 23,15,7,14,1,8,92,43,5,2,16,19,80,72,34 };
	int len = sizeof(num) / sizeof(num[0]);
	cout << "排序前：" << endl;
	dispArray(num, len);
	cout << "直接插入排序后：" << endl;
	directInsertionSort(num, len);
	cout << "希尔排序后：" << endl;
	shellSort(num, len);
	cout << "冒泡排序后：" << endl;
	bubbleSort(num, len);
	int *a = new int[len];
	int i;
	for (i = 0; i < len; i++)
		a[i] = num[i];
	cout << "快速排序后：" << endl;
	quickSort(a, 0, len-1);
	dispArray(a, len);
	cout << "堆排序后：" << endl;
	heapSort(num, len);
	cout << "选择排序后：" << endl;
	selectSort(num, len);
}

