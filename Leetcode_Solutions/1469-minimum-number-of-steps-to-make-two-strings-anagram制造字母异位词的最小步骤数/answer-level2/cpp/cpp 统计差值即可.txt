思路：
1.记录第一个字符串的字母情况
2.遍历第二个，在前面的记录基础上减
3.把记录中的正值相加就是需要的结果

```
class Solution {
public:
    int minSteps(string s, string t) {
        array<int, 26> record{0};
        for (auto ch : s) {
            record[ch - 'a']++;
        }
        for (auto ch : t) {
            record[ch - 'a']--;
        }
        int result = 0;
        for (auto num : record) {
            if (num > 0) {
                result += num;
            }
        }
        return result;
    }
};
```
