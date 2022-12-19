![image.png](https://pic.leetcode-cn.com/a776f8cd4c80b2f537c5b2394649dda83578fa4118a4c6cbff8aec64a9def144-image.png)

```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());//排序
        int a,b;
        int n=nums.size();
        a=nums[0]*nums[1]*nums[n-1];//两个复数、一个正数
        b=nums[n-1]*nums[n-2]*nums[n-3];//三个正数
        return a>b?a:b;
    }
};
```
