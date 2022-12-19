### 解题思路
由于题中的n为1~30，故可建立一个string类型的数组，且str[1] = "1"。
当i > 1时，str[i]即是数str[i-1]的数字个数，初始便是取str[i-1]的第一个数字c，令cnt = 1。
然后从str[i-1]的第二个数字(j = 1)开始，检查该数字是否和c一样，若一样则cnt++；
当数到不一样的数字的时候，表示此时j之前相同的c已经数完，应加入str[i]中。
接着令c为当前j处的新数字，继续循环数数直到将str[i-1]所有数字数完。
将最后未统计的c再加入str[i]中。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string str[31];
        str[1] = "1";
        for (int i = 2; i < 31; i++) {
            char c = str[i-1][0];
            int cnt = 1;
            for (int j = 1; j < str[i-1].length(); j++) {
                if (c == str[i-1][j]) {
                    cnt++;
                } else {
                    str[i].push_back(cnt + '0');
                    str[i].push_back(c);
                    c = str[i-1][j];
                    cnt = 1;
                }
            }
            str[i].push_back(cnt + '0');
            str[i].push_back(c);
        }
        return str[n];
    }
};
```