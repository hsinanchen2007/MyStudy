### 解题思路
遍历数组，将数字存储在map容器中。
遍历map容器求相邻元素间的差值，每次遍历记录最大的差值。

执行用时 :12 ms, 在所有 C++ 提交中击败了58.41% 的用户
内存消耗 :12.6 MB, 在所有 C++ 提交中击败了5.27%的用户

### 代码

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
		map<int, int> mps;
		for (auto num : nums) mps[num]++;
        if (mps.size() < 2) return 0;
		int tmp = INT_MAX;
		int res = INT_MIN;
		for (auto mp : mps)
		{
			tmp = mp.first - tmp;
			res = max(res, tmp);
			tmp = mp.first;
		}
		return res;
    }
};
```