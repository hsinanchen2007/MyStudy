### 解题思路

### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() == true) {
                st.push(s[i]);
                m[s[i]] = 1;
                continue;
            }
            if (m[s[i]] == 1) {
                continue;
            }
            while (true) {
                if (st.empty() == false && st.top() >= s[i]) {
                    if (s.find(st.top(), i) != std::string::npos) {
                        m[st.top()] = 0;
                        st.pop();
                    } else {
                        st.push(s[i]);
                        m[s[i]] = 1;
                        break;
                    }
                } else {
                    st.push(s[i]);
                    m[s[i]] = 1; 
                    break;
                }
            }
        }
        string res;
        while (st.size() > 0) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```