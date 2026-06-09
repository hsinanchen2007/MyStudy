### 解题思路
重点就是逆序和去除后面的空格

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0){
            if(s[i] == ' ') return result;
            else    result++;
            i--;
        }
        return result;
    }
};
```