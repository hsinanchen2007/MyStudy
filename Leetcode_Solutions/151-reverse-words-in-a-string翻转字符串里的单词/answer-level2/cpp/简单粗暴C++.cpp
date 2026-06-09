### 解题思路
此处撰写解题思路
新手上路，过来瞧瞧......将单词入栈，最后出栈拼接句子。。。。。。
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else {
                if (temp.size() != 0) {
                    sta.push(temp);
                }
                temp.clear();
            }
        }
        if (temp.size() != 0) {
            sta.push(temp);
        }
        string strout;
        while (sta.size() > 0) {
            if (sta.size() != 1) {
                strout += sta.top();
                strout += " ";
                sta.pop();
            } else if (sta.size() == 1) {
                strout += sta.top();
                sta.pop();
            }
        }
        return strout;
    }
};
```