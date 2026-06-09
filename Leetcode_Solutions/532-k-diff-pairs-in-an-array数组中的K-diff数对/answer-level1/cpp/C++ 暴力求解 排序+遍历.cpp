### 解题思路
暴力求解:排序+遍历
时间复杂度最坏o(n^2)
### 代码

```cpp
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
        if(nums.size()<=1) return 0;//对于nums数组数量不足时，直接返回0
		sort(nums.begin(), nums.end());//对数组排序
		int count = 0;//统计个数
		for (int i=0;i<nums.size()-1;i++)//遍历
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j=i+1;j<nums.size();j++)
			{
				if (abs(nums[i]-nums[j])==k)
				{
					count++;
					break;//避免重复计算
				}
			}
		}
		return count;
	}
};
```