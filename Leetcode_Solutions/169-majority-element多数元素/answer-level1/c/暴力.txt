### 解题思路
暴力求解！！！
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int len=nums.size();
        int n=len/2;
        map<int,int> m;
        map<int,int>::iterator it_m;
        for(int i=0;i<len;i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=1;
            }
            else
            {
                m[nums[i]]+=1;
            }
        }
        for(it_m=m.begin();it_m!=m.end();it_m++)
        {
            if(it_m->second > n) return it_m->first;
        }
        return 0;
    }
};
```