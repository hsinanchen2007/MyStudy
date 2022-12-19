### 解题思路
**滑动窗口：**
1.可能性：题目要求子数组，说明必定连续，符合滑动窗口。
2.正确性：题目给出的是正整数数组，保证了累积是单调不减的。假如存在负数，滑动窗口应该解决不了。

### 代码

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        int product = 1;
        int left = 0, right = 0;
        while(right < nums.size()){
            product *= nums[right];
            while(product >= k){
                product = product / nums[left];
                left ++;
            }
            ans += right-left+1;
            right ++;
        }
        return ans;
    }
};
```