### 解题思路
思路还是二分法，但是判断条件设置为 ```right >= left```。这样可以把插入在头尾的情形，比如```[0,1],2```同时包括进去。
不知道这样想对不对，结果是通过的，欢迎指正

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right)/2;
		while (right >= left)
		{
			 mid = (left + right) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			
		}
		return left ;
    }
};
```