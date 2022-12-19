### 解题思路
![捕获.JPG](https://pic.leetcode-cn.com/05332040a96017ce2b2f56cd55286624b78925be4c84c92dd0e5d70b72c12822-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<char> sta;
        bool flag = false;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '.') {
                sta.push('.');
                sta.push('.');
                sta.push('.');
                i+=2;
            } else if (path[i] == '.' && path[i + 1] == '.' && (path[i + 2] == '/' || i == path.size() - 2)) {
                if (sta.size() > 1 && sta.top() == '/') {
                    sta.pop();
                }
                while (sta.size() > 1 && sta.top() != '/') {
                    sta.pop();
                }
                i+=2;
            } else if (path[i] == '/' || (path[i] == '.' && path[i + 1] == '/') || (path[i] == '.' && i == path.size() - 1)) {
                if (!flag) {
                    sta.push('/');
                    flag = true;
                }
            } else {
                sta.push(path[i]);
                flag = false;
            }
        }
        if (sta.size() == 1 && sta.top() == '/') {return "/";}
        if (sta.top() == '/') {sta.pop();}
        while (!sta.empty()) {
            res += sta.top();
            sta.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```