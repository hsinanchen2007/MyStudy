### 解题思路
二分查找算法：如果当前索引与对应数值相等，就将left=mid+1；否则right=mid；最后返回left。
![捕获.JPG](https://pic.leetcode-cn.com/e38e6479c35e651b9dc89e810808de76ddb3f1a393310195235b475fa3c703e0-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```