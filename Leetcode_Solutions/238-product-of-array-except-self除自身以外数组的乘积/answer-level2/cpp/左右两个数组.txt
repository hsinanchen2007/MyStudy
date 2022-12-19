### 解题思路
1. 分为左右两个数组，双重动态规划
2. 是我今天笔试题，竟然没做出来，55
![image.png](https://pic.leetcode-cn.com/6f5521bc080d4992db8de3c9ca82d3869a708afa9667a03ea56fff1fceb1d363-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> left(len),right(len),ans(len);
        left[0]=nums[0];
        for(int i=1;i<len;i++)
        {
            left[i]=nums[i]*left[i-1];
        }  
        right[len-1]=nums[len-1];
        for(int j=len-2;j!=0;j--)
        {
            right[j]=nums[j]*right[j+1];
        }
        for(int i=0;i<len;i++)
        {
            if(i==0) 
            {
                ans[i]=right[i+1];
                continue;
            }
            if(i==len-1)
            {
                ans[i]=left[len-2];
                continue;
            }
            
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
};
```