### 解题思路
判定条件弄清楚就好。
用栈模拟“向上一级”的操作。

![image.png](https://pic.leetcode-cn.com/9ae978345e58b2e70550058a31024777bdeb5c98d9ff615de553bb39bca35040-image.png)

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        if(path.length() == 0) return "";
        stack<string> st;
        string tmp;
        path += "/";
        int now = 0;
        while(now < path.length() - 1)
        {
            while(path[now] == '/' && now < path.length() - 1) now ++;
            if(now >= path.length() - 1) break;
            if(path[now] == '.' && (path[now + 1] =='.' || path[now + 1] == '/'))
            {
                if(path[now + 1] == '.' && (now + 2 > path.length() - 1 || path[now + 2] == '/'))            
                {
                    if(!st.empty()) st.pop();
                    now = now + 2;
                    continue;
                }
                else 
                    if(path[now + 1] != '.')
                    {
                        now ++;
                        continue;
                    }
            }
            tmp = "";
            while(path[now] != '/')
            {
                tmp += path[now];
                now ++;
            }
            st.push(tmp);
        }
        tmp = "";
        if(st.empty()) return "/";
        while(!st.empty())
        {
            tmp = "/" + st.top() + tmp;
            st.pop();
        }
        return tmp;
    }
};
```