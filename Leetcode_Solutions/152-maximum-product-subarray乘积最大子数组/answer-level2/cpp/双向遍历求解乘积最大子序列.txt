### 解题思路
双向遍历
![捕获1.JPG](https://pic.leetcode-cn.com/3464cb1a260cd7556c3c42e12910ad1875ab7cdd7a04f5336753e190d447b703-%E6%8D%95%E8%8E%B71.JPG)

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 双向遍历
        int result = INT_MIN;
        int left_max = 1;
        for (int i = 0; i < nums.size(); i++) {
            left_max *= nums[i];
            result = max(result, left_max);
            if (left_max == 0) {left_max = 1;}
        }
        int right_max = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            right_max *= nums[i];
            result = max(result, right_max);
            if (right_max == 0) {right_max = 1;}
        }
        return result;
    }
};
```