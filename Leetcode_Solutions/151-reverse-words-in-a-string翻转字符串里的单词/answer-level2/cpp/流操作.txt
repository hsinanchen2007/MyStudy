### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp;
        stack<string> st;
        while(getline(is, tmp, ' ')){
            if(tmp == " " || tmp.empty()) continue;
            st.push(tmp);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top() + ' ';
            st.pop();
        }

        return ans.substr(0, ans.size()-1);
    }
};
```