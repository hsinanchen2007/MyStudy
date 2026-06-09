### 解题思路
采用暴力破解法，记住要解决尾部为空格的情况

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.length() - 1;i >= 0;i--)
        {
            if(s[i] != ' ')
            {   
                count++;
            }
            else if(count != 0) //这里让count ！= 0是为了避免在尾部为空格的时候跳出
            {
                break;
            }
        }
        return count;
    }
};
```