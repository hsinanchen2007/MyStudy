### 解题思路
来源：https://www.geeksfor@geeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
（去掉@）
	

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
		for (int n : nums) 
        {
			if (s.find(n) != s.end()) continue;
			s.insert(n);
			auto it = s.upper_bound(n);
			if (it != s.end()) s.erase(it);
		}
		return s.size();
    }
};
```