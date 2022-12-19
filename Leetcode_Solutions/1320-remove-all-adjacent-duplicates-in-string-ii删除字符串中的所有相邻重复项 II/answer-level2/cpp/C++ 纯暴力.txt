### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int flag = 1;
        while (flag) {
            int tmp = s.size();
            for (int i = 0; i <= (int)(s.size()) - k; i++) {
                int del = 1;
                for (int j = 1; j < k; j++) {
                    if (s[i] != s[i + j]) {
                        del = 0;
                        break;
                    }
                }
                if (del) {
                    s.erase(i, k);
                }
            }
            if (tmp == s.size() || s.size() < k) {
                flag = 0;
            }
        }

        return s;
    }
};
```