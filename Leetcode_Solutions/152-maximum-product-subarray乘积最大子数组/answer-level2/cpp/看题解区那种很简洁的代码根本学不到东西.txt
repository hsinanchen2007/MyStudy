主要注意到一个细节，即只有当数组只有一个元素，且这个元素为负值时，输出才会为负值，其他情况必定非负
我用a和b两个数分别记录正值和负值，并且根据当前数据的正负性分别做不同方式更新
```cpp
class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		int res = nums[0];
		/*如果只有1个值，并且为负，下面的计算带进去就错了*/
		if (nums.size() == 1)
		{
			return res;
		}
		int a = 0;	//a的值要么为最大的乘积正值，要么为0
		int b = 0;	//b的值要么为最小的乘积负值，要么为0
		for (auto num : nums)
		{
			if (num > 0)
			{
				a = a == 0 ? num : a*num;	//原先有正值就乘上，为0就更新为当前正值
				b = b == 0 ? 0 : b*num;		//原先由负值就乘上，为0就继续为0
			}
			else if (num < 0)
			{
				int temp = a;	//备份用来更新b
				a = b == 0 ? 0 : b*num;			//原先b由负值就乘上，b为0就继续为0
				b = temp == 0 ? num : temp*num;	//原先a有正值就乘上，a为0没有就更新当前负值
			}
			else
			{
				a = 0;		//双双置零
				b = 0;
			}
			res = max(res, a);
		}
		return res;
	}
};
```