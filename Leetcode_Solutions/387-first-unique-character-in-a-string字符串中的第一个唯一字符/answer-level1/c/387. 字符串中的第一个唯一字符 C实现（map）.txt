### 解题思路
此处撰写解题思路

### 代码

```c
#define CHARNUM 26

int firstUniqChar(char * s){
    if (!s) {
        return -1;
    }
    int* m = (int*)malloc(sizeof(int) * CHARNUM);
    memset(m, 0, sizeof(int) * CHARNUM);
    int idx = 0;
    while (s[idx] != '\0') {
        m[s[idx] - 'a']++;
        ++idx;
    }
    idx = 0;
    while (s[idx] != '\0') {
        if (m[s[idx] - 'a'] == 1) {
            return idx;
        }
        ++idx;
    }
    free(m);
    return -1;
}
```