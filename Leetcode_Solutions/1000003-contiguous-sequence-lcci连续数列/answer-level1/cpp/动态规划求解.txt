### 解题思路
![image.png](https://pic.leetcode-cn.com/eefb1d6adc243d50940246816b8819cd5b7a5d66ea4b514a41aa7483f30638f0-image.png)


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
           int n=nums.size();
           int max=nums[0];
          int sum=max;
          for(int i=1;i<n;i++)
          {
              if(max<0)
              {
                 max=nums[i];
              }
              else
              {
                  max+=nums[i];
              }
              if(max>sum)
              {
                  sum=max;
              }
          }
          return sum;
    }
};
```