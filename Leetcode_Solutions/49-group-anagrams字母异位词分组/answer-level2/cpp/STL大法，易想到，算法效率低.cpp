### 解题思路
map<char,int> 一个map用来存一个字符串出现的各个字母次数
map<map<char,int>,vector<string> > 一个map用来存字母出现次数相同的字符串们
就很好写了，当然内存和时间都不理想

### 代码

```cpp
class Solution {
public:    
    map<map<char,int>,vector<string> >mp;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i=0,len=strs.size();i<len;++i){
            map<char,int>m; // 
            for(int j=0,l=strs[i].size();j<l;++j)
                m[strs[i][j]]++;   // 该字符串字母出现次数
            mp[m].push_back(strs[i]);  //  该字母出现次数相同的map插入该字符串
        }
        vector<vector<string> >ans;
        map<map<char,int>,vector<string> >::iterator it = mp.begin();
        for(;it!=mp.end();++it)
            ans.push_back(it->second);
        return ans;
    }
};
```