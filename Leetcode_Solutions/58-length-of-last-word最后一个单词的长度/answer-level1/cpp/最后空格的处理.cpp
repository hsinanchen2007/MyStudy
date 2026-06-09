### 解题思路
O(n)既可，主要最后字符是空格的处理

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                result++;
            }else{
                i++;
                while(i < s.length() && s[i] == ' ') i++;
                if(i == s.length()) return result;
                else result = 1;
            }
        }
        return result;
    }
};
```