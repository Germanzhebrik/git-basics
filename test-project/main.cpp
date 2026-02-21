#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void qsort(std::vector<int>& a, int left, int right, int& cnt)
// Сортировка a[left...right] включительно
{
	if (right <= left)
		return;
	int q = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (++cnt && a[i] < q)
			++i;
		while (++cnt && q < a[j])
			--j;
		if (i <= j) {
			std::swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	qsort(a, left, j, cnt);
	qsort(a, i, right, cnt);
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> perm(n);
	for (size_t i = 0; i != n; ++i) perm[i] = i + 1;
	std::vector<int> max_perm(n);
	int max = 0;
	do {
		int cnt = 0;
		std::vector<int> temp = perm;
		qsort(temp, 0, temp.size() - 1, cnt);
		if (cnt > max) {
			max = cnt;
			max_perm = perm;
		}
	} while (std::next_permutation(std::begin(perm), std::end(perm)));
	for (auto el : max_perm) std::cout << el << ' ';
}