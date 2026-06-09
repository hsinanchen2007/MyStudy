### 解题思路
此处撰写解题思路
s1怎么排列不管，弄两个hash表，保存s1和s2的hash值，如果s2中包含s1的排列，则两个hash表示一样的。
### 代码

```c
#define MAXLEN 26
int hashs1[MAXLEN] = {0};
int hashs2[MAXLEN] = {0};

int Judgeisinclude(char *s2, int right, int len)
{
    int left = right - len + 1;
    memset(hashs2, 0, sizeof(int) * MAXLEN);
    for (int i = left; i<= right; i++) {
        int val = s2[i] - 'a';
        hashs2[val]++;
    }
    int res = memcmp(hashs1, hashs2, sizeof(int) * MAXLEN); // 包含相同的字符，两个hash表要完全一致
    return (res == 0);
}

bool checkInclusion(char *s1, char *s2){
    if (s1 == NULL || s2 == NULL) {
        return false;
    }
    int len1 = strlen(s1);
    if (len1 < 1) {
        return true;
    }
    int len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 + 1));
    memset(temp, 0, sizeof(char) * (len1 + 1));
    
    memset(hashs1, 0, sizeof(int) * MAXLEN);
    memset(hashs2, 0, sizeof(int) * MAXLEN);

    for (int i = 0; i < len1; i++) {
        int val1 = s1[i] - 'a';
        hashs1[val1]++;
    }
    
    int left = 0;
    int right = len1 - 1;
    for (int i = right; i < len2; i++) {
        int res = Judgeisinclude(s2, i, len1);
        //printf(" i=%d res=%d\n ", i, res);
        if (res) {
            //printf(" i=%d........................\n ", i);
            return true;
        }
    }

    return false;
}
```