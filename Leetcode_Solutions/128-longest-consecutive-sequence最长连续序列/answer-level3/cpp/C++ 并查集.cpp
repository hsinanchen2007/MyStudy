### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    unordered_map<int,int> um;
    unordered_map<int,int> cnt;
    int find(int x)
    {
        int r=x;
        while(r!=um[r])
        {
            r=um[r];
        }
        //路径压缩
        int i=x,j;
        while(i!=um[i])
        {
            j=um[i];
            um[i]=r;
            i=j;
        }
        return r;
    }
    int merge(int x,int y)
    {
        int a=find(x);
        int b=find(y);
        if(a==b)
        {
            return cnt[a];
        }
        um[a]=b;
        cnt[b]+=cnt[a];
        return cnt[b];    
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]=1;
            um[nums[i]]=nums[i];
        }
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            if(um.count(nums[i]+1))
                res=max(res,merge(nums[i],nums[i]+1));
        }
        return res;
    }
};
```