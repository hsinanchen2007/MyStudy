### 解题思路
将字符串反转再遍历，用标志flag区分单词前的空格和单词后的空格，count计数返回

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0) return 0;

        string save;
        int count = 0;
        bool flag = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                if(!flag) continue;
                break;
            }
            count++;
            flag = 1;
        }
        return count;
    }
};
```