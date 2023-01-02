#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <bits/stdc++.h>
using namespace std;

#include "ds/cartesian.hpp"

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	auto ct = cartesian(A);
	auto par = ct.par;
	par[ct.rt] = ct.rt;
	for (int i = 0; i < N; i++) {
		cout << par[i] << " \n"[i+1==N];
	}
}
