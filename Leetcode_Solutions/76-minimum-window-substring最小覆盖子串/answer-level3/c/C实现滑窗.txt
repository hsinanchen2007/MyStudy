![image.png](https://pic.leetcode-cn.com/09478f14dfcc1997812349eb689e935814fc7ef2b11af0743ac4d0639799f88a-image.png)


```
#define MAX 256

int g_count[MAX];

char * minWindow(char * s, char * t){
    char *result;
    int sSize = strlen(s);
    int tSize = strlen(t);
    int start = 0;
    int end = sSize;
    int idx = 0;
    int len = 0;
    int flag = 0;
    int l = 0;

    result = (char *)malloc(sSize + 1);
    memset(g_count, 0, MAX * sizeof(int)); 

    result[0] = '\0';
    if (s == NULL || t == NULL || sSize < tSize) {
        return result;
    }

    for (int i = 0; i < tSize; i++) {
        g_count[t[i]]++;
    }

    for (int r = 0; r < sSize; r++) {
        if (--g_count[s[r]] >= 0) { //如果减后不小于零，表示该元素在数组t中存在
            len++;
            flag = 0;
            while (len == tSize) {
                flag = 1;
                if (++g_count[s[l++]] > 0) { //前面for循环已经减过一遍，如果复原后大于0，表示该元素在数组t中存在
                    len--;
                }
            }
            if (flag && r - l + 1 < end - start) { //更新时机
                end = r;
                start = l - 1;
            }               
        }             
    }

    if (l == 0) { //不存在相同元素
        return result;
    }

    while (start <= end) {
        result[idx++] = s[start++];
    }
    result[idx] = '\0';

    return result;
}
```
