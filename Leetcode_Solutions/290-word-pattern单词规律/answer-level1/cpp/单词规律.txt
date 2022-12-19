### 解题思路
如果只用一个哈希表过不了这样的用例：
"abba"
"dog dog dog dog"

"ab"
"dog dog"

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string>m1;
        unordered_map<string,char>m2;
        istringstream is(str);
        vector<string>word;
        string temp;
        while(is>>temp)
            word.push_back(temp);
        
        if(word.size() != pattern.size())
            return false;
        
        for(int i = 0;i < pattern.size();i++){
            if(m1.count(pattern[i]) == 0 && m2.count(word[i]) == 0)
            {
                m1[pattern[i]] = word[i];
                m2[word[i]] = pattern[i];
            }
            else
            {
                if(m1[pattern[i]] != word[i] || m2[word[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};
```