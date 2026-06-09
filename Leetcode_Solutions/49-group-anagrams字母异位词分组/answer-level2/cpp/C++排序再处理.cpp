```C++ []
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> map;

        for(string s: strs){
            vector<char> key;
            vector<string> value;
            for(char c: s){
                key.push_back(c);
            }
            sort(key.begin(), key.end());
            value.push_back(s);
            if(!map.count(key))
                map[key] = value;
            else map[key].push_back(s); 
        }
        vector<vector<string>> ans;
        for(auto it = map.begin(); it != map.end(); ++it)
            ans.push_back(it->second);
        return ans;
            
    }
};
```

刚开始会想着key的值用set来实现，最后发现当一个单词中有相同的字母的时候会出现错误，因此改为vector然后排序来实现。