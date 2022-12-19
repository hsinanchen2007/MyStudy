```C++ []
class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            if (c == '/') {
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }
        string res;
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty()) res = "/";
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6201c353aaa6143a3a0f99c3964effb52bec2707e40e2140ec8cab635925c3d6-image.png)
