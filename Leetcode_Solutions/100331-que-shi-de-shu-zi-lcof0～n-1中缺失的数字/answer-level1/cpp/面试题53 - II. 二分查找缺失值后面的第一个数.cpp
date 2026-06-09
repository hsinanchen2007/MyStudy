```cpp

// 二分查找缺失值后面的第一个数
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int l = 0 ;
        int r = nums.size() - 1;
 
        if (nums[r] == r) // 当刚好缺失了最后一个数时，特殊情况
            return r + 1;

        while (l < r) {   // 正常情况下，二分查找缺失值后面的第一个数，l==r 时退出循环 找着了
            int mid = (l + r) >> 1;
            if (nums[mid] != mid)
                r = mid;
            else
                l = mid + 1;
        }
        return r;

    }
};
```