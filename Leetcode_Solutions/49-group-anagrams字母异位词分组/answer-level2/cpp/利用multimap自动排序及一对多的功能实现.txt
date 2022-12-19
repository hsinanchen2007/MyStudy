### 解题思路
通过sort对向量中的每个字符串进行排序，然后将排序后的与排序前的作为一对键值对插入multimap中，之所以用multimap是因为它可以实现一对多的数据结构，并且在插入multimap时，可以实现自动排序。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return vector<vector<string>>() ;
        vector<vector<string>> ss;
        multimap<string ,string> strMultimap;

        for(int i = 0; i < len; i++)
        {
            string strTemp = strs[i];
            sort(strTemp.begin(), strTemp.end());
            strMultimap.insert(make_pair(strTemp, strs[i]));
        }

        string s = strMultimap.begin()->first;
        vector<string> v;
        for(auto iter = strMultimap.begin(); iter != strMultimap.end(); iter++)
        {
            if(s == iter->first)
            {
                v.push_back(iter->second);
            }
            else
            {
                ss.push_back(v);
                v.clear();
                s = iter->first;
                v.push_back(iter->second);
            }
        }
        ss.push_back(v);

        return ss;
    }
};
```