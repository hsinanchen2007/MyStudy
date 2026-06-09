### 解题思路：
从左到右遍历字符串，找到')'就向前找'('，找到了就把这一对全部改写为一个特定字符，遍历一遍以后没有配对的括号都留在了原处。
然后再遍历一遍，计算连续的特定字符的最大长度即可。

### 代码

```c
void findMatch(char *s, int index)
{
    int i;
    for (i = index - 1; i >= 0; i--) {
        if (s[i] == '(') {
            s[i] = '0';
            s[index] = '0';
            break;
        }
    }
    return;
}

int longestValidParentheses(char * s){
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ')') {
            findMatch(s, i);
        }
    }
    int count = 0;
    int max = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            count++;
        } else {
            if (max < count) {
                max = count;
            }
            count = 0;
        }
    }
    if (max < count) {
        max = count;
    }

    return max;
}
```