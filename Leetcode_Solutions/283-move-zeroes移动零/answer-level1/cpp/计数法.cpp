执行用时 :8 ms, 在所有 C++ 提交中击败了85.92%的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了5.37%的用户

### 代码

```cpp
class Solution {
public:
	void moveZeroes(vector<int>& nums) 
	{
		int len = nums.size();
		int unzeronum = 0, zeronum = 0;
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == 0)
				zeronum++;
			else
			{
				nums[unzeronum] = nums[i];
				unzeronum++;
			}
		}
		for (int i = 1; i <= zeronum; ++i)
		{
			nums[len - i] = 0;
		}
	}
};
```