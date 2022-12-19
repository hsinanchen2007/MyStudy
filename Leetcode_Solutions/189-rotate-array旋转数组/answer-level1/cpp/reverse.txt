上周一家公司的笔试题变形，循环右移k位字符串

`1234567`假如右移3位，那么我们要取`5671234`。
以上过程可以分为三步
- 1234567反转成7654321
- 765反转成567
- 4321反转成1234

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
    }
};
```

