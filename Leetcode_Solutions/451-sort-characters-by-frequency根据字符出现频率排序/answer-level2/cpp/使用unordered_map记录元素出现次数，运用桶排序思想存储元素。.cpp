### 解题思路
使用unordered_map记录元素出现次数，运用桶排序思想存储元素。

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        string res;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        vector<char> vec[n+1];
        for(unordered_map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
            vec[it->second].push_back(it->first);
        for(int i=n;i>=0;i--)
            for(int j=0;j<vec[i].size();j++)
                for(int k=0;k<i;k++)
                    res+=vec[i][j];
        return res;
    }
};
```