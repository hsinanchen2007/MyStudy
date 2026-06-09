### 解题思路
此处撰写解题思路

### 代码

```c
char findTheDifference(char * s, char * t){
    char res = t[0];
    int sz1, sz2, i;

    sz1 = strlen(s);
    sz2 = strlen(t);

    for (i = 1; i < sz2; i++) {
        res ^= t[i];
    }

    for (i = 0; i < sz1; i++) {
        res ^= s[i];
    }

    return res;
}
```