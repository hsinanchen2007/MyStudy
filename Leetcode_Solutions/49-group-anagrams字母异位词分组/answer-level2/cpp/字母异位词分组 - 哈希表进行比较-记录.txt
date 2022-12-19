### 解题思路
对字符排序，利用哈希表键进行比较，判断是否是字母异味词，然后用vector作为哈希表值进行id的记录。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> vstrs ;

        if(strs.empty()) return vstrs ;
  
        unordered_map<string , vector<int>> vmaps ;
        for(int i=0 ; i<strs.size() ; i++)
        {
            string str = strs[i] ;
            sort(str.begin() , str.end()) ;
            vmaps[str].push_back(i) ;
        }

        for(auto &vmap : vmaps)
        {
            vector<string> vstr ;
            for(auto &id : vmap.second)
                vstr.push_back(strs[id]) ;

            vstrs.push_back(vstr) ;
        }

        return vstrs ;
    }
};
```