
###  遍历字符串分别判断即可
**需要注意的几点：**
1. L和R是一组，U和D是一组，分别设置两组相反数；
2. 时间复杂度：之遍历一遍数组，即$O(n)$
```c++
class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.empty()) return true;
        int res = 0;
        for (auto c : moves){
            if (c == 'L') res += 1;
            if (c == 'R') res += -1;
            if (c == 'U') res += -2;
            if (c == 'D') res += 2;
        }
        return res == 0 ? true : false;
    }
};
```
