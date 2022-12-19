### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>hash;
        for(int i=0;i<strs.size();i++){
            string str1=strs[i];
            sort(str1.begin(),str1.end());
            hash[str1].push_back(strs[i]);
        }
        vector<vector<string>>rel;
        for(map<string,vector<string>>::iterator it=hash.begin();it!=hash.end();it++){
            rel.push_back(it->second);
        }
        return rel;
    }
};
```