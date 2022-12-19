### 解题思路
先去除字符串中所有的空格，再利用栈的方法存储左右括号和符号进行运算优先级判定

### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        //先去除字符串中所有的空格
        int index = 0;
        if( !s.empty())
        {
            while( (index = s.find(' ',index)) != string::npos)
            {
                s.erase(index,1);
            }
        }

        //利用栈的方法存储左右括号进行运算
        stack<int> st;
        int res = 0, n = s.size(), sign = 1;
        for(int i=0; i<n; i++) {
            int num = 0;
            if(s[i] >= '0') {
                while(i<n && s[i] >= '0') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                res += sign * num;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5766401d72a186a86f0fc2a86bc446c85dc0c8cef4f4af8a451a5f241f2a756f-image.png)
