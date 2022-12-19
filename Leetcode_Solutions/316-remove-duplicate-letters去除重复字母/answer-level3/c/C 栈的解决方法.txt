### 思路

结果存到一个栈里，对于当前字符 c
1. 如果栈里面已经有字符 c, 舍弃c
2. 如果栈为空、栈顶元素小于 c、c在当前字符串唯一，c入栈， 否则栈顶元素出栈。

### 代码

```C
char * removeDuplicateLetters(char * s){
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * (len + 1));
    memset(stack, '\0', len + 1);

    int count[26];
    memset(count, 0, sizeof(int) * 26);
    for(int i = 0; i < len; i++) {
        char c = s[i];
        count[c - 'a']++;
    }

    int stack_count[26];
    memset(stack_count, 0, sizeof(int) * 26);
    int pos = 0;
    int top = -1;
    
    while(s[pos] != '\0') {
        char c = s[pos];
        if (stack_count[c - 'a'] != 0) {
            pos++;
            count[c - 'a']--;
            continue;
        }
        while(top != -1 && stack[top] > c && count[stack[top] - 'a'] != 0) {
            stack_count[stack[top] - 'a']--;
            stack[top] = '\0';
            top--;
        }
        top++;
        stack[top] = c;
        stack_count[c - 'a']++;
        count[c - 'a']--;
        pos++;
    }
    return stack;
}
```