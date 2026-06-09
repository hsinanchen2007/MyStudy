### 解题思路
    栈底保存上一个有效字符串结束的位置。遇到左括号，左括号位置入栈。遇到右括号，出栈。出栈后：
    如果栈不是空的，可以用当前位置减去栈顶保存的位置，得到当前有效字符串的长度。同时更新最大字符串长度。
    如果栈是空的，说明已经没有匹配的左括号了，则将当前位置入栈。后面计算字符串长度，以此为起点。
    初始状态下，先将-1入栈，作为有效字符串位置的起点。

### 代码

```c
int longestValidParentheses(char * s){
    if (s == NULL || s[0] == '\0') {
        return 0;
    }

    int sLen = strlen(s);
    int *longStr = (char *)malloc((sLen + 1) * sizeof(int));
    memset(longStr, 0, (sLen + 1) * sizeof(int));
    int headIndex = 0;
    int maxLen = 0;
    int curLen = 0;

    /*栈底保存上一个有效字符串结束的位置。遇到左括号，左括号位置入栈。遇到右括号，出栈。出栈后：
      如果栈不是空的，可以用当前位置减去栈顶保存的位置，得到当前有效字符串的长度。同时更新最大字符串长度。
      如果栈是空的，说明已经没有匹配的左括号了，则将当前位置入栈。后面计算字符串长度，以此为起点。
      初始状态下，先将-1入栈，作为有效字符串位置的起点。
      */
    longStr[headIndex] = -1;
    headIndex++;
    for (int i = 0; i < sLen; i++) {
        switch(s[i]) {
            case '(':
                longStr[headIndex] = i;
                headIndex++;
                break;
            case ')':
                if (headIndex != 0) {
                    headIndex--;
                    longStr[headIndex] = 0;
                }

                if (headIndex == 0) {
                    longStr[headIndex] = i;  
                    headIndex++;
                } else {
                    curLen = i - longStr[headIndex - 1];
                    maxLen = (maxLen > curLen) ? maxLen : curLen;
                }
                break;
            default:
                break;
        }
    }

    free(longStr);

    return maxLen;
}
```