![QQ截图20200228171915.png](https://pic.leetcode-cn.com/3a82c7c88353e1e2e250d917dc4eb7da4d2eab2f07a54dd30faaee1e2e8c4c3f-QQ%E6%88%AA%E5%9B%BE20200228171915.png)


从后往前遍历数组，能前一个位置满足题意的最小长度，如果满足就让最小长度更新为1.

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length=nums.size();
        int i=length-2;
        int j=1;
        for(;i>=0;i--)
        {
            if(nums[i]>=j)
            {
                j=1;
            }
            else
            {
                j++;
            }
        }
        if(j==1)
        return true;
        else
        return false;
    }
};
```