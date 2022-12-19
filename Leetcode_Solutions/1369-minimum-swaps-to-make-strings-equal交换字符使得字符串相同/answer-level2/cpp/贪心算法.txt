1) 简化为几个基本cases
2) 位运算求奇偶（注意：位运算优先级低于关系运算符）

```
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x = 0;
        int y = 0;
        for(int i = 0; i < s1.length(); ++i)
        {
            if(s1[i] != s2[i])
            {
                if(s1[i] == 'x') x++;
                else y++;

            }
        }
        if(((x + y) & 1) != 0) return -1;
        if((x & 1) == 0) return (x + y) / 2;
        else return (x + y -1) / 2 + 2;
    }
};
```
