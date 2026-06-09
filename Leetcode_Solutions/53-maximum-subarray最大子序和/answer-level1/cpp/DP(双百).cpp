### 解题思路
首先，我们分析题意，假设f(n)为一段连续子数组第n个数时最大连续子数组的值，那么f(n)==f(n-1)或者f(n)==f(n-1)+nums[i],取其中的较大值。而当nums[i]为负数时，我们要判断是否重该值重新开始计数，如果前面的和加上这个数小于这个数的话，就要从这个数重新开始计数了，数组的连续性被破坏，我们则要把当前连续数组的最大值储存下来，遍历完整个数组后，输出这最大值就得到了具有最大和的连续子数组。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        {   return 0;   }
        int num = nums[0], m = 0;
        for(int i = 0; i < nums.size(); i++){
            m = max(nums[i], nums[i]+m);
            num = max(num, m);
        }
        return num;
    }
};
```