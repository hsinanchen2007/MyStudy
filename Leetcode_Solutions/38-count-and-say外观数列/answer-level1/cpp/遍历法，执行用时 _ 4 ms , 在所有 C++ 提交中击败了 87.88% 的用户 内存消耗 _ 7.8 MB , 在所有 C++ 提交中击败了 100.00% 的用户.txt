### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        int j;
        string str = "1";
        string str_next;
        int count = 0;
        char str_value;
        for (int i = 1; i < n; ++i) {
            str_value = str.front();
            for (j = 0; j < str.length(); ++j) {
                if (str_value == str.at(j)) {
                    count ++;
                } else{
                    str_next += to_string(count);
                    str_next.push_back(str_value);
                    str_value = str.at(j);
                    count = 1;
                }
            }
            if (j == str.length()) {
                str_next += to_string(count);
                str_next.push_back(str_value);
                count = 0;
            }
            str = str_next;
            str_next = "";
        }
        return str;
    }
};
```