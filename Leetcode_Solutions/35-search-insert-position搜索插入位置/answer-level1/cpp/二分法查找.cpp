### 解题思路
二分法查找目标值target，若命中则返回其位置；若循环结束则表示未命中，lo指针则表示target应该插入的位置。详情如代码。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;      //lo为target未命中时应该插入的位置
    }
};
```