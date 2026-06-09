### 解题思路
滑动窗口方法快很多啊！~

### 代码

```c
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
static int find(int L, int R, char *s)
{
    while (L < R) {
        if (s[L] == s[R]) {
            return L;
        }
        L += 1;
    }
    return -1;
}
int lengthOfLongestSubstring(char * s){
    int L = 0, R = 0, max = -1;
    int ret = -1;
    int len = strlen(s);

    if (s == NULL || len == 0)
        return 0;
    if (len == 1) {
        return 1;
    }
    while (R < len) {
        R += 1;
       // printf("R %d\n", R);
        if (R >= len) {
            break;
        }
        ret = find(L, R, s);
        if (ret == -1) {
            max = MAX(max, R - L + 1);
          //  printf("max %d\n", max);
        } else {
            max = MAX(max, R - L);
            L = ret + 1;
        }
    }
    return max;
}
```