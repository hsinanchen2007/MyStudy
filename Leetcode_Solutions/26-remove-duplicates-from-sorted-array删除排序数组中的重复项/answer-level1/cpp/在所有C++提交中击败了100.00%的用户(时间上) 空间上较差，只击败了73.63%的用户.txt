### 解题思路
设置两个指针，一个用来遍历vector，一个用来存储最终结果并修改vector

### 代码

```cpp
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 0 || len==1)
		{
			return len;
		}
		int result = 1; // 设置result作为最终结果以及用来修改vector的内容
		for (int i = 1; i < len; i++)
		{
			if (nums[i] != nums[i-1])
			{
				result++;
				nums[result - 1] = nums[i];
			}
		}
		return result;
	}
};
```