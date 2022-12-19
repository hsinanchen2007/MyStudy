思路很直接，用一个map存储每一个对应的字符串，在经过字符串本身的排序之后，字母异位的字符串肯定是拥有同一个键值的；
所以我们可以直接根据索引将原字符串中的字符添加进去。之后再遍历一遍map即可得到答案。时间复杂度就是O（N），只不过牺牲了较多的空间。
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >res;
        vector<string> str(strs);
        unordered_map<string,vector<string> >mp;
        for(int i=0; i<strs.size(); i++) {
            sort(str[i].begin(), str[i].end());
            mp[str[i]].push_back(strs[i]);
        }
        for(auto i : mp) {
            res.push_back(i.second);
        }
        return res;
    }
};
```
