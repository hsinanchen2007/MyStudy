### 解题思路
几个注意点：
1. 文件或文件夹名中含'.'
2. 空字符串也可以是deque中一元素
3. 把初始字符串path首尾都加上'/',对于边界情况好处理得多
4. 遍历时，连续的'/'可以不做任何处理
5. 用getline函数切割字符串更方便

### 代码

```cpp
class Solution {
    // 文件名中含"."
public:
    string simplifyPath(string path) {
        deque<char> str;
        int len = path.size();
        if (len == 0) {
            return "";
        }
        path.insert(0, 1, '/');
        path += "/";
        str.push_back(path[0]);
        for (int i = 1; i < len + 2; i++) {
            if (path[i] == '/' && path[i - 1] == '/') {
                continue;
            }
            str.push_back(path[i]);
        }
        deque<string> ans;
        string curr;
        while (str.empty() == false) {
            curr += str.front();
            str.pop_front();
            if (str.empty() == true) {
                break;
            }
            if (str.front() == '/') {
                if (curr == "/.") {
                    curr = "";
                    continue;
                } else if (curr == "/..") {                  
                    if (ans.size() > 0) {
                            ans.pop_back();
                    } 
                    curr = "";
                } else {
                    ans.push_back(curr);
                    curr = "";
                }
            }
        }
        string result;
        for (auto str : ans) {
            for (auto ch : str) {
                result += ch;
            }
        }
        if (result == "" && len > 0) {
            result = "/";
        }
        return result;      
    }
};
```