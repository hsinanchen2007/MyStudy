### 解题思路
二分查找，如果没找到,则返回left(待插入位置)

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while(left <= right)
        {
            mid = left + (right - left) / 2;

            if(nums.at(mid) == target)
            {
                return mid;
            }
            else if(target > nums.at(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};
```