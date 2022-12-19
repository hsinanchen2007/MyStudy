感觉还是常规做法简单一点
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=-1;//上一个0的位置
        int res=0;
        nums.push_back(0);//末尾插个0
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if((i-l-1)>res)
                res=i-l-1;
                l=i;//更新上一个0的位置
            }
        }
        return res;
    }
};
```
