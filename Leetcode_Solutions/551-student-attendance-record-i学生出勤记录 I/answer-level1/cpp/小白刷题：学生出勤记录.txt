find函数判断是否有三个以上的连续L，遍历统计A的个数

代码：
```
class Solution {
public:
    bool checkRecord(string s) {
        if (s.find("LLL") == s.npos) {
            int num = 0;
            int len = s.length();
            for (int i = 0; i < len; i++) {
                if (s[i] == 'A')
                    num++;
                if (num > 1)
                    return false;
            }
            return true;
        }
        return false;
    }
};
```
