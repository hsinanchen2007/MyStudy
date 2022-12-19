### 解题思路
unordered_map+桶排序

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> count[n+1],res;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            count[it->second].push_back(it->first);
        for(int i=n;i>=0;i--)
            if(count[i].size()==0)
                continue;
            else
                for(int j=0;j<count[i].size();j++){
                    res.push_back(count[i][j]);
                    k--;
                    if(k==0)
                        return res;
                }
        return res;
    }
};
```