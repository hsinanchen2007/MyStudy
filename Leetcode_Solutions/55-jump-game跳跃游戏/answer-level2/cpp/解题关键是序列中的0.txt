### 解题思路
筛选出序列中的所有0,检测当前0前面的所有位置是否能跳过这个0，如果能，继续往后筛选直到遍历结束，如果不能，返回false。

### 代码

```cpp
class Solution {
public:
	bool canJump(std::vector<int>& nums) {
		//1.如果nums中除了最后一位外无0，返回true，
		//2.先筛选出nums中的所有0，看能否越过这个0。
		if (nums.size() == 1)
			return true;
		if (nums[0] == 0)
			return false;
		int zero;
		bool flag = false;
		for (int i = 1;i < nums.size() - 1;i++)
		{
			if (nums[i] == 0)
			{  
				zero = i;
				while (nums[i++] == 0)//找到0之后第一个不是0的位置
				{
					if (i == nums.size())
						break;
				}
				i--;
				int j = 0,k = zero-1;
				for (;j <= k;j++, k--)
				{
					if (nums[k] >= (i- k) || nums[j] >= (i- j))
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					return false;
				}
				else
					flag = false;
			}
		}
		return true;
	}
};
```