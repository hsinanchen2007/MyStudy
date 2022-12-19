### 解题思路
双指针，一个快指针 j 控制右边界，一个慢指针 i 控制左边界。
有ans的结果：
![image.png](https://pic.leetcode-cn.com/fef528dbeda46a8064b070f0288df18742bb1a9dc5a2a14e1bbbfd75ed9709fd-image.png)
### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, ans = 0xffff;
        for(int i = 0, j = 0; j < nums.size() && i <= j; j++) {
            sum += nums[j];
            while(sum >= s) {
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        return ans==0xffff ? 0: ans;
    }
};
```