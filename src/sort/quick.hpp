#include <iostream>
#include <random>
#include <algorithm>    // std::swap

template <typename Dtype>
class QuickSort {
public:
	QuickSort() {}
	~QuickSort() {}
	
	static void sort(Dtype *data, int length);
private:
	/*
		[Error] cannot call member function 
		'void QuickSort<Dtype>::do_sort(Dtype*, int, int) 
		[with Dtype = int]' without object
		��̬�����е��õĺ���Ҳ�����Ǿ�̬��
		��Ȼ�������޷���õ���ʵ�壬������� 
	*/
	static int partition(Dtype *data, int start, int end);
	static void do_sort(Dtype *data, int start, int end);
};

template <typename Dtype>
void QuickSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	do_sort(data, 0, length-1);
}

template <typename Dtype>
void QuickSort<Dtype>::do_sort(Dtype *data, int start, int end)
{
	if (start == end)
		return;
	
	int index = partition(data, start, end);
	if (index > start)
		do_sort(data, start, index-1);
		
	if (index<end)
		do_sort(data, index+1, end);
}

template <typename Dtype>
int QuickSort<Dtype>::partition(Dtype *data, int start, int end)
{
	if (start == end)
		return start;
		
	int index = std::rand() % (end-start) + start;
	//std::swap(data[index], data[end]);
	data[index] += data[end];
	data[end] = data[index] - data[end];
	data[index] -= data[end];
	int small = start-1;
	for (int i=start; i<end; i++) {
		if (data[i] < data[end]) {
			small++;
			if (small != i) {
				data[small] += data[i];
				data[i] = data[small] - data[i];
				data[small] -= data[i];
			}
		}
	}
	
	small++;
	data[small] += data[end];
	data[end] = data[small] - data[end];
	data[small] -= data[end];
	
	return small;	
}