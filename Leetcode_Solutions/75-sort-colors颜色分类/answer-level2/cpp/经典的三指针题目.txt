这道题肯定很容易先想到双指针方法，但发现只有两个指针的话，没办法维护好三个区间，因此必须要再加一个指针
三指针这道题最需要注意的是其中的**不对称性**，与左边交换之后p就可以移动，而与右边交换之后p不能移动，必须要再审查一次
```cpp
class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		int p = 0;
		/*注意，p是从left方向往right走，左右是不对称的
		因此交换时候的指针移动也是不对称的*/
		while (p <= right)
		{
			if (nums[p] == 0)
			{
				/*因为p肯定在left右边，
				所以交换过来的肯定是1，不需要再审查*/
				swap(nums[left++], nums[p++]);
			}
			else if (nums[p] == 2)
			{
				/*交换过来的可能是0,1,2，需要再审查*/
				swap(nums[right--], nums[p]);
			}
			else
			{
				p++;
			}
		}
	}
};
```