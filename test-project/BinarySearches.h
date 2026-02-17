#pragma once

template <typename Container>
int lbinsearch(const Container& data) {
	int l = 0;
	int r = data.size() - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (elem <= mid) r = mid;
		else l = mid + 1;
	}
	return l;
}

template <typename Container>
int rbinsearch(const Container& data) {
	int l = 0;
	int r = data.size() - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (elem <= mid) r = mid - 1;
		else l = mid;
	}
	return l;
}