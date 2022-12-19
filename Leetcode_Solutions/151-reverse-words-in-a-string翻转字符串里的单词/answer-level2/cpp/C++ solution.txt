### 解题思路
用stringstream切分单词

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if (s == "") return s;
        int index = s.size()-1;
        while (index >= 0 && s[index] == ' ') index--;
        s = s.substr(0, index + 1);
        stringstream ss(s);
        vector<string> vs;
        string word;
        while (!ss.eof()) {
            ss >> word;
            vs.push_back(word);
        }
        string ans;
        for (int i = vs.size()-1; i >= 0; i--) {
            ans += vs[i];
            if (i > 0) 
                ans += " ";
        }
        return ans;
    }
};
```