# 思路：
1，函数的调用是天然的栈结构，没有比用栈更适合本题的了
```C++ []
class Solution {
public:
    vector<string> split(const string& s, char sp) {
        vector<string> v;
        string t;
        for (auto c : s) {
            if (c == sp) {
                if (!t.empty()) {
                    v.push_back(t);
                    t.clear();
                }
            } else {
                t += c;
            }
        }
        if (!t.empty()) v.push_back(t);
        return v;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> res(n, 0);
        int prev_t = -1;
        for (auto& s : logs) {
            auto items = split(s, ':');
            int id = stoi(items[0]);
            int t = stoi(items[2]);
            ++res[id];
            if (!st.empty() && prev_t != -1) {
                res[st.top()] += t - prev_t - 1;
            }
            if (items[1] == "start") {
                st.push(id);
            } else {
                st.pop();
            }
            prev_t = t;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/084b0d1e95046835d60359dd30455cc49a0849628641354822b16b2c5f82203b-image.png)
