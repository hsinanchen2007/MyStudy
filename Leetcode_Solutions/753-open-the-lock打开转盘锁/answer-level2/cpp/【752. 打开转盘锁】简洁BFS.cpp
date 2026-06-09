## 思路
参考：[[LeetCode] Open the Lock 开锁](https://www.cnblogs.com/grandyang/p/8449211.html)
### 代码
```c++
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> uset(deadends.begin(), deadends.end());
        if (uset.count("0000")) return -1;
        if (uset.count(target)) return 0;
        int res = 0;
        unordered_set<string> visited = {"0000"};
        queue<string> que{{"0000"}};
        while (!que.empty()) {
            ++res;
            for (int k = que.size(); k > 0; --k) {
                string t = que.front();
                que.pop();
                for (int i = 0; i < t.size(); ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (j == 0) continue;
                        string str = t;
                        str[i] = (t[i] - '0' + 10 + j) % 10 + '0';
                        if (str == target) return res;
                        if (!visited.count(str) && !uset.count(str)) que.push(str);
                        visited.insert(str);
                    }
                }
            }
        }
        return -1;
    }
};
```

#### 另一种写法
使用拼接法进行字符置换。
```c++
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> uset(deadends.begin(), deadends.end());
        if (uset.count("0000")) return -1;
        if (uset.count(target)) return 0;
        int res = 0;
        unordered_set<string> visited = {"0000"};
        queue<string> que{{"0000"}};
        while (!que.empty()) {
            ++res;
            for (int k = que.size(); k > 0; --k) {
                string t = que.front();
                que.pop();
                for (int i = 0; i < t.size(); ++i) {
                    char c = t[i];
                    string str1 = t.substr(0, i) + to_string(c == '9' ? 0 : c - '0' + 1) + t.substr(i + 1);
                    string str2 = t.substr(0, i) + to_string(c == '0' ? 9 : c - '0' - 1) + t.substr(i + 1);
                    if (str1 == target || str2 == target) return res;
                    if (!visited.count(str1) && !uset.count(str1)) que.push(str1);
                    if (!visited.count(str2) && !uset.count(str2)) que.push(str2);
                    visited.insert(str1);
                    visited.insert(str2);
                }
            }
        }
        return -1;
    }
};
```
