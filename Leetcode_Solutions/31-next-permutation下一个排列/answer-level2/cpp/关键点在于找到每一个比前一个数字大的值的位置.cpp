![image.png](https://pic.leetcode-cn.com/db0300020083fb2e375e3d363534aa76d97d9ca410f410107480a1282aae9e45-image.png)

### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		int num[len] = { 0 };
		int flag = 0;
		int i;
		if (len >= 2)//只有len大于等于2的时候才需要计算
		{
			int tmp = nums[0];
			//找到第一个比前一个值大的点
			/*如果不存在这样的点，就说明输入的数组是倒序排序的
			再直接将其倒转回来就可以了*/
			for (i = 1; i < len; i++)
			{
				if (tmp >= nums[i])
				{
					tmp = nums[i];
				}
				else//找到第一个比前一个值大的点
				{
					flag = i;
					break;
				}
			}
			if (flag == 0)//flag==0，说明输入的数组是倒序排序的
			{
				for (i = len - 1; i >= 0; i--)
				{
					num[len - 1 - i] = nums[i];
				}
				for (i = 0; i < len; i++)
				{
					nums[i] = num[i];
				}
			}
			else
			{
				if (flag == len - 1)//如果是最后的一个数字，那么就把它跟前一个交换一下就可以了
				{
					num[0] = nums[len - 1];
					nums[len - 1] = nums[len - 2];
					nums[len - 2] = num[0];
				}
				else
				{
					while (flag != len - 1)//否则进入循环，继续找到比前一个值大的点的位置
					{
						int cc = flag;
						tmp = nums[flag];
						for (i = flag + 1; i < len; i++)
						{
							if (tmp >= nums[i])
							{
								tmp = nums[i];
							}
							else
							{
								flag = i;
								break;
							}
						}
						if (flag == cc)
						{
							num[0] = nums[flag];
							int index = flag;
							for (i = flag+1; i < len; i++)
							{
								if (nums[i] > nums[flag - 1])
								{
									if (nums[i] < nums[flag])
									{
										index = i;
									}
								}
							}
							num[0] = nums[index];
							nums[index] = nums[flag-1];
							nums[flag-1] = num[0];
							sort(nums.begin() + flag, nums.end());
							break;
						}
						if (flag == len - 1)
						{
							num[0] = nums[len - 1];
							nums[len - 1] = nums[len - 2];
							nums[len - 2] = num[0];
							break;
						}
					}
				}
			}
		}
	}
};
```