### 解题思路
可能有些伙伴还不理解题目吧，我这里简单说明一下：
+ 路径以`'/'`为分界线；要注意可能存在`"////"`这种情况
+ 遇到`".."`，则切换到上一级目录
+ 其他情况可不做处理


### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            // 以 / 为分隔符
            if (c == '/') {
                // 切换上一集目录
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } 
                // 上一个 '/' 到 下一个 '/'
                else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }

        // 遍历栈
        string result;
        while (!st.empty()) {
            string s = st.top();
            st.pop();
            result = "/" + s + result;
        }
        if(result.empty()) result = "/";
        return result;
    }
};
```