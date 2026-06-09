### 解题思路
大佬轻喷

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s)
    {
        if (s.length() == 0) return "";
        vector<string> word = split(s, ' ');
        string str = "";
        for (int i = word.size() - 1; i > 0; i--)
        {
            str += word[i];
            str.push_back(' ');
        }
        str += word[0];
        return str;
    }
    vector<string> split(string str, char ch)
    {
        vector<string> subs;
        for (int i = -1, k = 0; k < str.length(); )
        {
            while (str[k] == ch) k++;
            i++;
            subs.push_back("");
            while (str[k] != ch && k < str.length())
            {
                subs[i] += str[k];
                k++;
            }
            if (subs[i] == "") subs.pop_back();
        }
        return subs;
    }
};
```