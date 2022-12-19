### 解题思路
![capture_20200228213217842(1).bmp](https://pic.leetcode-cn.com/abf20c97fbccbc71272ac4ad6833a576a1d58d1b503391fbdbd92c42cf15ee2a-capture_20200228213217842\(1\).bmp)


### 代码

```c
char output[10001] = { 0 };
char* replaceSpace(char* s) {
    int len = strlen(s);
    memset(output,0,10001);
    char* out = output;
    int index = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            strcat(out + index, "%20");
            index += 3;
        }
        else
        {
            *(out + index) = *s;
            index++;
        }
        s++;
    }
    return out;
}
```