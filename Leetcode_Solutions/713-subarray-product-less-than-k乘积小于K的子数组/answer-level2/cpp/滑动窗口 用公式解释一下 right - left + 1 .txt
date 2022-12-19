解法参照官方题解的双指针

其中代码
``` C++
ans += right - left + 1
```

可以根据如下的累加公式来理解（right - left + 1 看作是 n）

$\sum_1^n x = n + \sum_1^{n-1} x$

附上C++代码：

``` C++
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1)
      return 0;
    int product = 1, ans = 0, left = 0;
    for (int right = 0; right < nums.size(); right++) {
      product *= nums[right];
      while (product >= k) {
        product /= nums[left];
        left++;
      }
      ans += right - left + 1;
    }
    return ans;
  }
};
```