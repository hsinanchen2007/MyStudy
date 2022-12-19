### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[right] == right) return right + 1;//缺失的是最后一个元素的情况
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == mid )
            {
                left = mid + 1;
            }
            else if(nums[mid] != mid)
            {
                right = mid;
            }
        }
        return left;//二分查找法 左=中+1 右=中 为基本格式 return 为 left
    }
};
```