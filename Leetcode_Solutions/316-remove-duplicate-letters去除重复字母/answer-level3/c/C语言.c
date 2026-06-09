![image.png](https://pic.leetcode-cn.com/b4cf4270838edbaf26ea611a567700c16dc41e9a6315a14b3f6c0f4143848005-image.png)

### 解题思路
看着大佬的思路写的

### 代码

```c
#define MAXSIZE 128
bool IsContain(char *stack, char a, int len)
{
    for (int i = 0; i <= len; i++) {
        if (stack[i] == a) {
            return true;
        }
    }
    return false;
}
char *removeDuplicateLetters(char *s)
{
    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    int hash[MAXSIZE] = {0};
    for (int i = 0; i < len; i++) {
        hash[s[i]]++;
    }
    char *stack = (char *)calloc(MAXSIZE, sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (IsContain(stack, s[i], top)) {
            hash[s[i]]--;
        } else {
            while (top > -1 && stack[top] > s[i] && hash[stack[top]] > 1) {
                hash[stack[top]]--;
                top--;
            }
            top++;
            stack[top] = s[i];
        }
    }
    return stack;
}
```