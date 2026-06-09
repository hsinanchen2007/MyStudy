### 解题思路
转换成ASCII码求和后作差，差值即为多余的字母
### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_s = 0, sum_t = 0;
        char res;

        for(auto c:s) sum_s += c;
        for(auto c:t) sum_t += c;
        res = sum_t - sum_s;
        return res;
    }
};
```