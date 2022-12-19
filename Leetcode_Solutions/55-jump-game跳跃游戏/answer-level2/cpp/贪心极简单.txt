时间复杂度为线性，空间复杂度为常数，且程序不会改变输入向量nums。
思路如下：
只要发现，对于每一个0，能够越过它就可以。如果有任何一个0越不过去，则就不行。我用ma来表示在当前点之前的最大的能够走到的index。ma=max(ma,nums[i]+i)
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return true;
        int index=0;
        int ma=0;
        for(int i=0;i<len;i++)
        {
            if(i<(len-1)&&nums[i]==0&&ma<=i)
            {
                return false;
            }
            else if(nums[i]!=0)
            {
                ma = max(ma,nums[i]+i);
            }
        }
        return true;
    }
};
```
