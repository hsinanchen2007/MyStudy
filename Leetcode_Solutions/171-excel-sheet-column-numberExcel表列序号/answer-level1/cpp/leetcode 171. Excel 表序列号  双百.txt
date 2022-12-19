### 解题思路
26 进制问题

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int col = 0;
        for(int i = 0; i < len; i++)
        {
            int tmp = s[i] - 'A' + 1;
            int k = len - i -1;
            while(k-- >0)
            {
                tmp = tmp * 26;

            }
                
            col += tmp;
        }
        return col;
    }
};
```