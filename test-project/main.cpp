#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

void merge(std::vector<char>& data, int l, int mid, int r) {
	int nleft = mid + 1 - l;
	int nright = r - mid;
	std::vector<char> left(nleft), right(nright);
	for (size_t i = 0; i != nleft; ++i) left[i] = data[l + i];
	for (size_t i = 0; i != nright; ++i) right[i] = data[mid + 1 + i];
	int i = 0, j = 0, k = l;
	while (i < nleft && j < nright) {
		if (left[i] < right[j]) data[k++] = left[i++];
		else data[k++] = right[j++];
	}
	for (i; i != nleft; ++i) data[k++] = left[i];
	for (j; j != nright; ++j) data[k++] = right[j];
}

void MergeSort(std::vector<char>& data, int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		MergeSort(data, l, mid);
		MergeSort(data, mid + 1, r);
		merge(data, l, mid, r);
	}
}

template <typename T>
void print(std::vector<T> data) {
	for (const auto& el : data) {
		std::cout << el;
	}
	std::cout << std::endl;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<char> str(n);
	for (size_t i = 0; i != n; ++i) std::cin >> str[i];
	MergeSort(str, 0, str.size() - 1);
	std::queue<char> syms;
	char elem = str[0];
	char mid = ' ';
	int cnt = 1;
	bool first_odd = true;
	for (size_t i = 1; i != str.size(); ++i) {
		if (str[i] == elem) {
			cnt++;
		}
		else {
			if (cnt % 2 == 1 && first_odd) {
				mid = elem;
				first_odd = false;
			}
			for (size_t i = 0; i < cnt / 2; ++i) syms.push(elem);
			elem = str[i];
			cnt = 1;
		}
	}
	if (cnt % 2 == 1 && first_odd) {
		mid = elem;
		first_odd = false;
	}
	for (size_t i = 0; i < cnt / 2; ++i) syms.push(elem);
	if (mid != ' ') {
		std::vector<char> answer(syms.size() * 2 + 1);
		int i = 0, j = answer.size() - 1;
		while (i < j) {
			char tmp = syms.front();
			syms.pop();
			answer[i++] = tmp;
			answer[j--] = tmp;
		}
		answer[i] = mid;
		print(answer);
	}
	else {
		std::vector<char> answer(syms.size() * 2 + 1);
		int i = 0, j = answer.size() - 1;
		while (i < j) {
			char tmp = syms.front();
			syms.pop();
			answer[i++] = tmp;
			answer[j--] = tmp;
		}
		print(answer);
	}
	
}