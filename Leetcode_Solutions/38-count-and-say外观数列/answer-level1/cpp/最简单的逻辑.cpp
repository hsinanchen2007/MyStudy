### 解题思路
感觉我这个逻辑应该是最容易懂得了。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i)
        {
            int count = 1;
            string tmp = "";
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[j] == s[j + 1])
                {
                    ++count;
                }
                else
                {
                    tmp += to_string(count) + s[j];
                    count = 1;
                }
            }
            s = tmp;
        }
        return s;
    }
};
```