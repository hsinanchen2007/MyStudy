### 解题思路
先用哈希表存储每个数字出现的次数，然后对于哈希表里面的每个键，查看是否存在（该键+1），如果存在，计算该和鞋子序列是否为最长的序列。

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>mp;
		int maxx = 0;
		for (int i : nums) {
			mp[i]++;
		}
		for (auto i : mp) {
			if (mp.count(i.first + 1))
				maxx = max(maxx, i.second + mp[i.first + 1]);
		}
		return maxx;
    }
};
```