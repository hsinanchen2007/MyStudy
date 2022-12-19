离散化+线段树模板题
```
class Solution {
	unordered_map<int, int> mp;
	unordered_map<int, int> remp;
	static const int maxn = 5050;
	int tree[maxn << 2], add[maxn << 2];
	void push_up(int rt) {
		tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
	}

	void push_down(int rt, int m) {
		if (add[rt]) {
			int a= (m - m >> 1)*add[rt];
			int b= (m >> 1)*add[rt];
			tree[rt << 1] += (m - (m >> 1))*add[rt];
			tree[rt << 1 | 1] += (m >> 1)*add[rt];
			add[rt << 1] += add[rt];
			add[rt << 1 | 1] += add[rt];
			add[rt] = 0;
		}
	}

	void bulid(int l, int r, int rt) {
		add[rt] = 0;
		if (l == r) { tree[rt] = 0; return; }
		int mid = (l + r) >> 1;
		bulid(l, mid, rt << 1);
		bulid(mid + 1, r, rt << 1 | 1);
		push_up(rt);
	}

	void update(int a, int b, int c, int l, int r, int rt) {
		if (a <= l && b >= r) {
			tree[rt] += (r - l + 1)*c;
			add[rt] += c;
			return;
		}
		push_down(rt, r - l + 1);
		int mid = (l + r) >> 1;
		if (a <= mid) update(a, b, c, l, mid, rt << 1);
		if (b > mid) update(a, b, c, mid + 1, r, rt << 1 | 1);
		push_up(rt);
	}

	int query(int a, int b, int l, int r, int rt) {
		if (a <= l && b >= r) 
			return tree[rt];
		push_down(rt, r - l + 1);
		int mid = (l + r) >> 1;
		int ans = 0;
		if (a <= mid) ans += query(a, b, l, mid, rt << 1);
		if (b > mid) ans += query(a, b, mid + 1, r, rt << 1 | 1);
		return ans;
	}

public:
	vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
		set<int> s;
		for (auto i : schedule) {
			for (auto j : i) {
				s.insert(j.start);
				s.insert(j.end);
			}
		}
		int index = 1;
		for (auto i : s) {
			mp[i] = index;
			remp[index] = i;
			index++;
		}
		bulid(1, s.size(), 1);
		for (auto i : schedule) {
			for (auto j : i) {
				int a = mp[j.start];
				int b = mp[j.end];
				update(a, b - 1, 1, 1, s.size(), 1);
			}
		}
		vector<Interval> ans;
		int start = -1;
		for (int i = 1; i < index; i++) {
			int curnum = query(i, i, 1, s.size(), 1);
			if (curnum == 0) {
				if (start == -1) start = i;
			}
			else {
				if (start != -1) {
					ans.push_back({ remp[start],remp[i] });
					start = -1;
				}
			}
		}
		return ans;
	}
};
```
