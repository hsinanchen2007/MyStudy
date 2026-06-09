### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vResult;
        int nLen=nums.size();
        if(nLen<=0)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        bool bS1=true;
        for(int i=0;i<nLen-3;++i)
        {
            if(!bS1)
            {
                break;//快速剪枝
            }
            if(i>0&&nums[i]==nums[i-1])
            {
                //以这个数字的开头是被处理过的
                continue;
            }
            bS1=false;
            for(int j=i+1;j<nLen-2;++j)
            { 
                if(j>i+1&&nums[j]==nums[j-1])
                {
                    //以这个数字的开头是被处理过的
                    continue;
                } 
                int n=j+1;
                int m=nLen-1;
                int nValue=0;
                while(n<m)
                {
                    nValue=nums[i]+nums[j]+nums[m]+nums[n];
                    if(nValue==target)
                    {
                        vResult.push_back({nums[i],nums[j],nums[m],nums[n]});
                        bS1=true;
                        //跳过重复的
                        while(n<m)
                        {
                            ++n;
                            if(nums[n]!=nums[n-1])
                            {
                                break;
                            }
                        }
                        while(n<m)
                        {
                            --m;
                            if(nums[m]!=nums[m+1])
                            {
                                break;
                            }
                        }
                        continue;
                    }
                    if(nValue<target)
                    {
                        bS1=true;
                        ++n;
                    }
                    if(nValue>target)
                    {
                        --m;
                    }
                }
            }
        }
        return vResult;
    }
};
```
简单进行了1次剪枝，不算吊车尾的