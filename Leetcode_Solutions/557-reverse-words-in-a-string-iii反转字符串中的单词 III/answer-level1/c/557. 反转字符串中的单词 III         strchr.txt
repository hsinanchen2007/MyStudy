### 解题思路


给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 


### 代码

```c
char * reverseWords(char * s) {
    int i = 0, len;
    char c = ' ', t, *start = s, *end;
    char *temp = strchr(s, c);

    while (temp) {
        end = temp - 1;
        while (start < end) {
            //printf("%c %c\n", *start, *end);
            t = *end;
            *end-- = *start;
            *start++ = t;
        }

        start = temp + 1;
        temp = strchr(start, c);
    }

    len = strlen(start) - 1;
    while (i < len) {
        t = start[len];
        start[len--] = start[i];
        start[i++] = t;
    }
    return s;
}
```