// min
template <class T> struct cartesian {
	int n, rt;
	vector<int> par, lch, rch;
	cartesian(const vector<T>& a) : n(int(a.size())), rt(0), 
	par(n, -1), lch(n, -1), rch(n, -1) {
		assert(n >= 1);
		vector<int> stk = {0};
		stk.reserve(n);
		for (int i = 1; i < n; i++) {
			if (a[stk.back()] > a[i]) {
				while (stk.size() >= 2 && a[stk.end()[-2]] > a[i]) {
					stk.pop_back();
				}
				if (stk.size() == 1) {
					rt = par[lch[i] = stk.back()] = i;
				} else {
					par[lch[i] = stk.back()] = i;
					rch[par[i] = stk.end()[-2]] = i;
				}
				stk.back() = i;
			} else {
				rch[par[i] = stk.back()] = i;
				stk.push_back(i);
			}
		}
	}
};
