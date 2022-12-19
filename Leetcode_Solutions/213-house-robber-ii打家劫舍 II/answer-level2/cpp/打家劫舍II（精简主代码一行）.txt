### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a6a278c7f931be8dc350ec765cbe2b389a11ab5b63651c7e79d00c583c8713d6-image.png)

### 代码

```cpp
class Solution {
public:
    int max_rob(vector<int>& nums,int s,int e)
    {
        if(nums.size()==0)return 0;
        if(s>e)return nums[0];
        int pre=0,cur=0;
        for(int i=s;i<=e;i++)
        {
            int tmp=cur;
            cur=max(pre+nums[i],cur);
            pre=tmp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        return max(max_rob(nums,0,nums.size()-2),max_rob(nums,1,nums.size()-1));
    }
};
```