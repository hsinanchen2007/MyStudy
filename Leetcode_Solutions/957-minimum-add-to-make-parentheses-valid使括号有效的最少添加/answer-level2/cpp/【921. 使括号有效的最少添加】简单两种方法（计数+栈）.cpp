## 思路一：计数
### 代码
```c++
class Solution {
public:
    int minAddToMakeValid(string S) {
        if (S.size() == 0) {
            return 0;
        }
        if (S.size() == 1) {
            return 1;
        }
        int cnt = 0;
        int res = 0;
        for (auto c : S) {
            if (c == '(') {
                ++cnt;
            } else {
                --cnt;
                if (cnt < 0) {
                    ++res;
                    cnt = 0;
                }
            }
        }
        return res + cnt;
    }
};
```
#### 简化代码
```c++
class Solution {
public:
    int minAddToMakeValid(string S) {
        int res = 0, cnt = 0;
        for (auto c : S) {
            cnt += c == '(' ? 1 : -1;
            if (cnt < 0) {
                ++res;
                ++cnt;
            }
        }
        return res + cnt;
    }
};
```


## 思路二：栈
### 代码
```c++
class Solution {
public:
    int minAddToMakeValid(string S) {
        if (S.size() == 0) {
            return 0;
        }
        if (S.size() == 1) {
            return 1;
        }
        stack<char> st;
        for (auto c : S) {
            if (st.empty() || st.top() != '(' || c == '(') {
                st.push(c);
            } else {
                st.pop();
            }
        }
        int res = 0;
        while (!st.empty()) {
            st.pop();
            ++res;
        }
        return res;
    }
};
```

