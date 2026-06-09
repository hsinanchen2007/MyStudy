### 解题思路
首先找到最后一个空格，然后开始记录位置，在从该位置向前遍历，直到再次出现空格，记录两空格之间的长度

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int n = s.size() - 1;
        while(s[n] == ' ')
            n --;
        for (int i = n; i >= 0;i --)
        {
            if(s[i] == ' ')
                return len;
            len ++ ;
        }
        return len;
    }
};
```