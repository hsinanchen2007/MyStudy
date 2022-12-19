### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       // 用哈希表
       vector<vector<string>> res;
       map<string,vector<string>> temp;
       for(int i = 0;i<strs.size();i++)
       {
           string o = strs[i];
           sort(o.begin(),o.end());
           map<string,vector<string>>::iterator tt = temp.find(o);
           if(tt == temp.end())
           { 
               vector<string> ii;
               ii.push_back(strs[i]);
               temp.insert(make_pair(o,ii));
           } else 
           {
              tt->second.push_back(strs[i]);
           }
       } 
        map<string,vector<string>>::iterator iter;
       for( iter = temp.begin() ;iter!=temp.end();iter++)
       {
           res.push_back(iter->second);
       }
       return res;
    }
};
```