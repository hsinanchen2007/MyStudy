### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<int> m_iStack;
        int res = 0;
        int n = s.size();
        int sign = 1;
        //cout<<INT_MAX<<endl;
        for(int i = 0; i < n; ++i) {
            int num = 0;
            if (s[i] >= '0' && s[i] <= '9') {
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    //cout<<num<<" "<<s[i]<<endl;
                    num = num * 10 + (s[i] - '0');
                    ++i;
                    //cout<<"test: "<<i<<endl;
                }
                //cout<<i<<endl;
                res = res + num * sign;
                --i;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                m_iStack.push(res);
                m_iStack.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                int top = m_iStack.top();
                m_iStack.pop();
                int val = m_iStack.top();
                m_iStack.pop();
                res = res * top;
                res = res + val;
            }
        }
        return res;
    }
};
```