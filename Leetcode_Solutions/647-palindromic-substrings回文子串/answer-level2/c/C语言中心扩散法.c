![Screen Shot 2019-08-19 at 19.06.05.png](https://pic.leetcode-cn.com/d285a58305c23bc20f8185364e82ff4e774fffb3fb738b4c47a2b5d5cf07d622-Screen%20Shot%202019-08-19%20at%2019.06.05.png)

指针操作，分别判断以某个字符为中心的偶数回文和奇数回文情况

```
int countSubstrings(char* s)
{
    char* start = s;
    int num = 0;

    while (*s != '\0') {
        num++;
        char *p = s + 1, *q = s;
        while (q >= start && *p != '\0' && *q == *p) {
            q--;
            p++;
            num++;
        }
        p = s + 1, q = s - 1;
        while (q >= start && *p != '\0' && *q == *p) {
            num++;
            q--;
            p++;
        }
        s++;
    }

    return num;
}
```
