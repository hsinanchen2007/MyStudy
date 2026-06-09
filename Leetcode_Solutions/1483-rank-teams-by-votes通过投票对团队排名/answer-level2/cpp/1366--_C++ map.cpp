### 解题思路

1、. 本题首先创建一个map.

char用来定位队员，map<int,int>用来累计成绩（int1用来定位排名，int2用来累计对应排名的成绩。

2、 二重循环，将每个队员累计的成绩得出

3、 对成绩排序，最后返回string串。

### 代码

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        string v = votes[0];
        map<char, map<int, int>> f;
        for (auto s : votes)
        {
            for (int i = 0; i < s.size(); ++ i)
                f[s[i]][i] ++;
        }
        sort(v.begin(), v.end(), [&](char a, char b) -> bool
        {
            for (int i = 0; i < v.size(); ++ i)
            {
                if (f[a][i] > f[b][i]) return 1;
                if (f[a][i] < f[b][i]) return 0;
            }
            return a < b;
        });
        return v;
    }
};
```

### 笔记

最后一个嵌套了一个匿名函数，即lambda函数。

作用是判断大小

捕获列表-->
[&] ：用到的任何外部变量都隐式按引用捕获

参数列表-->
(char a, char b)

函数体：判断两个数大小排名。
