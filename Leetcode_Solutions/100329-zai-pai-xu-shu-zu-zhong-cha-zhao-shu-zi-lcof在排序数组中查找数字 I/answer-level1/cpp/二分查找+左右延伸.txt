### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while(lo < hi)  //左闭右开区间[lo, hi)
        {
            int mid = (lo + hi) / 2;
            if(target == nums[mid])return mid;
            else if(target < nums[mid])
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        int index = binarySearch(nums, target);
        if(index == -1)return 0;
        int lo = index, hi = index;
        //左右延伸找到左右边界
        while(lo >= 0 && nums[lo] == target){ lo--; }  //注意边界条件，此外注意不要写nums[lo--]==target
        while(hi < nums.size() && nums[hi] == target){ hi++; }  //注意边界条件，此外注意不要写nums[hi++]==target
        return hi - lo - 1;
    }
};
```