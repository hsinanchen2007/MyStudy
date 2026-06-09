### 解题思路
此处撰写解题思路
分别用二分法查找左侧边界和右侧边界。查找左右边界原理一样，只是left和right位置偏移略微不同。
执行用时：在所有 C++ 提交中击败了87.24%的用户

### 代码

```cpp
class Solution {
public:
    int searchLeft(vector<int>& nums, int target)
    {
    	//查找左侧位置
    	int len = nums.size();
        int left = 0;
        int right = len-1;
        int find_index = -1;
        while ( left <= right )
        {
        	if (left == right)
        	{
        		if (nums[left] == target)
        		{
        			find_index = left;
        			break;
        		}
        		else
        		{
        			break;
        		}
        	}
        	int middle = (left + right)/2;
        	if (nums[middle] == target)
        	{
        		find_index = middle;
        		right = middle-1;
        	}
        	else if (nums[middle] > target)
        	{
        		right = middle-1;
        	}
        	else 
        	{
        		left = middle+1;
        	}
        	printf("left:%d middle:%d\n", left, right);
        }
        return find_index;
    }

    int searchRight(vector<int>& nums, int target)
    {
    	//查找左侧位置
    	int len = nums.size();
        int left = 0;
        int right = len-1;
        int find_index = -1;
        while ( left <= right )
        {
        	if (left == right)
        	{
        		if (nums[left] == target)
        		{
        			find_index = left;
        			break;
        		}
        		else
        		{
        			break;
        		}
        	}
        	int middle = (left + right)/2;
        	if (nums[middle] == target)
        	{
        		find_index = middle;
        		left = middle+1;
        	}
        	else if (nums[middle] > target)
        	{
        		right = middle-1;
        	}
        	else 
        	{
        		left = middle+1;
        	}
        	printf("left:%d middle:%d\n", left, right);
        }
        return find_index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
    	int len = nums.size();
    	std::vector<int> not_find;
    	std::vector<int> result;
    	not_find.push_back(-1);
    	not_find.push_back(-1);
    	if (len == 0)
    	{
    		return not_find;
    	}
        if (nums[0] > target || nums[len-1] < target)
        {
        	return not_find;
        }
        //二分查找，找到一个之后再左右查找就行
        int left = searchLeft(nums, target);
        cout << "left:" <<  left << endl;
        int right = searchRight(nums, target);
        cout << "right:" <<  right << endl;
        result.push_back(left);
        result.push_back(right); 
        return result;
    }
};
```