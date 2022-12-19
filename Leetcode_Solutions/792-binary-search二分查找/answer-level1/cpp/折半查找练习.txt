### 解题思路
就是折半查找的非递归写法

### 代码

```cpp
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(target==nums[mid]) 
                return mid;
            if(target<nums[mid]) 
                high=mid-1;
            else 
                low=mid+1;
        }
        return -1;
    }

};
```