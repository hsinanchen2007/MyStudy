### 解题思路


### 代码

```cpp
class Solution {
public:
	void Add(int idx, int x) {
		while (idx <= N) {
			lowbit[idx] += x;
			idx += (idx & -idx);
		}
	};
	int Query(int idx) {
		int res = 0;
		while (idx >= 1) {
			res += lowbit[idx];
			idx -= (idx & -idx);
		}
		return res;
	}
    int reversePairs(vector<int>& nums) {
		set<long> s;
		for (long num : nums) {
			s.insert(2 * num);
            s.insert(num);
		}
		unordered_map<long, int> rank;
		for (auto i : s) {
			rank[i] = rank.size() + 1;
		}
		this->N = rank.size();
		this->lowbit.assign(N + 1, 0);
		int sum = 0;
		for (int i = nums.size() - 1; i >= 0; --i) {
			// auto it = s.lower_bound(nums[i]);
			// int dis = distance(s.begin(), it);
			sum += Query(rank[nums[i]] - 1);
			Add(rank[2 * (long)nums[i]], 1);
		}
		return sum;
    }
private:
	int N;
	vector<int> lowbit;
};
```