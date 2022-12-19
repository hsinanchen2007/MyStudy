### 解题思路
定义栈来一层一层解析
![image.png](https://pic.leetcode-cn.com/781f9ba8d51cce2e4f98b43803853a4742fb4e17f35c563e9859ed1fbf84e134-image.png)

### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string tmp = "";
                string num = "";
                while (!st.empty()) {
                    if (st.top() == '[') {
                        st.pop();
                        while (!st.empty()) {
                            if (st.top() < '0' || st.top() > '9') {
                                break;
                            }
                            num = st.top() + num;
                            st.pop();
                        }
                        break;
                    }
                    tmp = st.top() + tmp;
                    st.pop();

                }
                int numDec = atoi(num.c_str());
                while (numDec--) {
                    for (int k = 0; k < tmp.length(); k++) {
                        st.push(tmp[k]);
                    }
                }
            } else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
```