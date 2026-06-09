### 解题思路
unordered_map存储出现次数+sort排序+判定

### 代码

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        vector<int> t;
        for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            t.push_back(it->second);
        sort(t.begin(),t.end());
        int res=0,len=arr.size();
        for(int i=t.size()-1;i>=0;i--){
            len-=t[i];
            res++;
            if(len<=arr.size()/2)   
                return res;
        }
        return res;
    }
};
```