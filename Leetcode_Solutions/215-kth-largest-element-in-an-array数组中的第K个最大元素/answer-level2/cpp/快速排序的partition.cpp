### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int partition(vector<int> &nums, int lo, int hi)
    {
        int pivot = nums[lo];
        while(lo < hi)
        {
            while(lo < hi && nums[hi] <= pivot)  //注意这里是找第k大的数，因此从大到小排序，有nums[hi] <= pivot
            {
                --hi;
            }
            nums[lo] = nums[hi];
            while(lo < hi && nums[lo] >= pivot)  /注意这里是找第k大的数，因此从大到小排序，有nums[lo] >= pivot
            {
                ++lo;
            }
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0 || k < 1)return -1;
        int lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi)
        {
            int p = partition(nums, lo, hi);
            if(p == k-1)return nums[p];
            else if(p < k-1)
            {
                lo = p+1;
            }
            else
            {
                hi = p-1;
            }
        }
        return -1;
    }
};
```