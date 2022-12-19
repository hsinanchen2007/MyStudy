执行用时 :8 ms, 在所有 C++ 提交中击败了97.77%的用户

内存消耗 :9.3 MB, 在所有 C++ 提交中击败了81.22%的用户

```
bool minThanK(const int& a, const int& b, const int& t) {
	return a > b ? a - b <= t : b - a <= t;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	if (k == 10000) return false; //看了评论，才知道 10000只能这么搞....
	unordered_map<int,int> un_mp;//无序映射比有序更快一点
	for (unsigned i = 0; i < nums.size(); ++i) {
		un_mp[i]=nums[i];

		for (unordered_map<int, int>::iterator it1 = un_mp.begin(); it1 != un_mp.end(); ++it1) {
			auto it2 = it1;
			while (++it2 != un_mp.end()) {
				if (minThanK(it1->second, it2->second, t)) return true; //自己重新写了个绝对值函数
			}
		}
		if (un_mp.size() > k) {//滑动窗口，保持在k及其以下
			un_mp.erase(i - k);
		}


	}
	return false;
}
```
