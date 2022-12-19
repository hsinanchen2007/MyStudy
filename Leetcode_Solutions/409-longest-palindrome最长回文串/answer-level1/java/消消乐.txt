### 解题思路
使用“消消乐”可以快速解答本题。

分析题目可以知道只要字母成双出现则可以组成1个回文字符，而字母‘A’~‘z’的范围在64以内，所以可以使用一个64位的类型变量的相应位来表示相应字母是否存在，如果不存在，则相应为置1；如果存在则表示可以组成一对，把他们消除且结果加2。然后使用异或运算消除出现的对。

### 代码

```c []
int longestPalindrome(char * s){
    int len = strlen(s);
    int reuslt = 0;
    long long dispel = 0;
    long long position = 0;
    for(int i=0; i<len;i++){
        position = 1LL <<(s[i]-'A');
        if(dispel& position)    reuslt+=2;
        dispel ^= position;
    }    

    if(dispel > 0) reuslt++;
    return reuslt;
}
```
```java []
class Solution {
    public int longestPalindrome(String s) {
        long dispel = 0;
        int len = s.length();
        int result = 0;
        long position = 0;
        char c = 0;
        for (int i=0; i<len; i++) {
            c = s.charAt(i);
            position = 1L<<(c-'A');
            if((dispel & position) > 0){
                result += 2;
            }
            dispel ^= position;
        }

        if(dispel > 0)  result++;
        return result;
    }
}
```
