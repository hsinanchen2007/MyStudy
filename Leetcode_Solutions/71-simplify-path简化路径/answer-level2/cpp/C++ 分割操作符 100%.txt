![image.png](https://pic.leetcode-cn.com/3d3fefe44a72c01f591582978de600c5505f107fb4f5e39b91c727fd246c1ff9-image.png)

相比自动机，这道题本人更倾向于用截断的操作来解释
本质上就是把一个字符串根据相邻的两个'/'给拆开，比如"/a/..//./b/../"，可以拆成
"/a", "/..", "/", "/.", "/b", "/.."几个字符串，把他们按顺序用vector记录(忽略最后一个'/'，如果最后不是就添加上)
剩下的就是把每个字符串当做一次操作就好，"/", "/."不理会，"/a"就加上，/..就一直回退到上一个'/'为止即可
```
class Solution {
public:
    vector<string> myStack;
    deque<string> myR;
    string simplifyPath(string path) {
        int f = 0;
        int next = 1;
        if (path.length() == 1) {
            return path;
        }
        int len = path.length();
        if (path[len - 1] != '/') {
            path += '/';
            len++;
        }
        
        while (next < len) {
            if (path[next] != '/') {
                next++;
            } else {
                string strT = path.substr(f, next - f);
                myStack.push_back(strT);
                f = next;
                next = f + 1;
            }
        }
        string res = "";
        for (int i = 0; i < myStack.size(); i++) {
            if (myStack[i] == "/" || myStack[i] == "/.") {
                continue;
            } else if (myStack[i] == "/..") {
                if (!res.empty()) {
                    int id = res.length();
                    while (res[id - 1] != '/' && res.length() != 0) {
                        id--;
                        res.pop_back();
                    }
                    res.pop_back();
                }
            } else {
                res += myStack[i];
            }
        }

        if (res == "") {
            res = "/";
        }
        return res;
    }
};
```
