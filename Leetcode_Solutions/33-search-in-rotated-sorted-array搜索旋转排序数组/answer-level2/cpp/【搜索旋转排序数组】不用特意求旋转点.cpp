### 分析
这题真是if else地狱！在里面转了好久才想明白（T T）  

思路还是二分查找，难点在于怎么处理旋转后的数组。  
既然是二分查找，关键还是要判断查找的值是在左侧还是右侧。  
不用在意如果是包含了旋转点的怎么判断，  
只要判断正常顺序的那一侧，是否包含target值，  
如果不在，那肯定在另一侧。  

例子1：  
4,5,6,7,0,1,2
mid计算后指向7，4567是正常顺序。  

例子2：  
5,6,7,0,1,2,3
mid计算后指向0，5670不是正常顺序，不用管了。  
0123是正常顺序。  
无论要查的是左侧的6还是右侧的2，  
都可以正确二分。  


----
解决方案为，  
1. 先判断正常顺序的是low - mid（左侧）还是mid - high（右侧）。  
2. 然后只对正常顺序的那一侧判断target是否在范围内，如果不在肯定就再另一侧。  


### 答题
``` C++
int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target) return mid;
		if (nums[low] <= nums[mid])
		{
			if (nums[low] <= target && target <= nums[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high - 1])
		{
			if (nums[mid] <= target && target <= nums[high - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
	}
	return low;
}

int search(vector<int>& nums, int target) 
{
	int i = lowerBound(nums, target, 0, nums.size());
	if (i == nums.size()) return -1;
	return (nums[i] == target) ? i : -1;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)