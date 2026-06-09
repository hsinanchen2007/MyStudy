### 解题思路

这一道问题可以同过滑动窗口的问题进行解决。

![image.png](https://pic.leetcode-cn.com/224763c3f08dfae65887d4d8e46de1e2151613643d722ecca7a1096c5b7adbc5-image.png)


### 代码

```cpp
class Solution 
{
public:
	vector<vector<int>> findContinuousSequence(int target) 
	{
		int l = 1;
		int r = 1;
		int end = target / 2;
		int sum = 0;
		vector<vector<int>> res;
		while (l <= end)
		{
			if (sum < target)
			{
				sum += r;
				r++;
			}
			else if (sum > target)
			{
				sum -= l;
				l++;
			}
			else
			{
				vector<int> res2;
				for (int i = l; i < r; ++i)
				{
					res2.push_back(i);
				}
				res.push_back(res2);
				sum -= l;
				l++;
			}
		}
		return res;
	}
};
```