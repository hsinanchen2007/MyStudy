因为每个字母只重复一遍，所以可以采用全排列方法做。

```cpp
class Solution {
public:
    vector<string> permutation(string S) {
        unordered_map<char, int> hash;
        for(auto&e:S)
            hash[e]++;
        vector<string> ans;
        string curStr = "";
        permutation(hash, ans, curStr);
        return ans;
    }

    void permutation(unordered_map<char, int>& hash, vector<string>& ans, string& curStr){
        if(curStr.size() == hash.size())
            ans.push_back(curStr);
        else{
            for(auto&e:hash){
                if(e.second>0){
                    e.second--;
                    curStr.push_back(e.first);
                    permutation(hash, ans, curStr);
                    e.second++;
                    curStr.pop_back();
                }
            }
        }
    }
};
```