### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)return -1;
        //二分查找
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi)  //这里是[lo,hi]闭区间
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] == mid)lo = mid + 1;  //说明前半部分是无缺失值的
            else hi = mid - 1;  //说明前半部分有缺失值
        }
        return lo;
    }
};
```