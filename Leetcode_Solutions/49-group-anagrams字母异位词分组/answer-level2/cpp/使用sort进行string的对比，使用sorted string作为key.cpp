### 解题思路
维护一个hashmap: unordered_map<string, vector<string>>
key是排序后的string
value，是所有排序后为这个string的vector<string>的集合

这道题目的关键是要能够相当使用sort进行string的对比，以及使用sorted string作为key

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size() == 0) return res;
        unordered_map<string, vector<string>> table;
        for(int i = 0; i < strs.size(); ++i){
            string si = strs[i];
            sort(si.begin(), si.end());
            if(!table.count(si)){
                vector<string> tmp;
                tmp.push_back(strs[i]);
                table[si] = tmp;
            }else{
                table[si].push_back(strs[i]);
            }
        }
        for(auto m: table){
            res.push_back(m.second);
        }
        return res;
    }
    bool cmpString(string s1, string s2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
```

### 结果
执行用时 : 160 ms , 在所有 C++ 提交中击败了 12.91% 的用户 
内存消耗 : 18.5 MB , 在所有 C++ 提交中击败了 83.65% 的用户