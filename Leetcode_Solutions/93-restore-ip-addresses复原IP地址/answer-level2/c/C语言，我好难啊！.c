C语言，我好难啊！
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char* makeIPAddress(char* s, int a, int b, int c, int d) {
    char ipAddress[20] = { 0 };
    int i = 0;
    int totalNum = 0;
    int flg = 0;  /* 定义flg保证每次判断第一个字符是否为0时只跑一次 */
    char* string = (char*)malloc(sizeof(char) * 20);

    /* 写第一段 */
    while (i < a) {
        if (a > 1 && s[i] == '0' && flg == 0) {
            return NULL;
        }
        flg = 1;
        ipAddress[i] = s[i];
        totalNum = totalNum * 10 + (s[i] - '0');
        i++;
    }
    if (totalNum > 255) {
        return NULL;
    }
    ipAddress[i] = '.';
    i++;  /* 加完指向第5个字符(i == 4) */
    flg = 0;  /* 清理标记 */
    /* 写第二段 */
    totalNum = 0;
    while (i < (a + b + 1)) {
        if (b > 1 && s[i - 1] == '0' && flg == 0) {
            return NULL;
        }
        flg = 1;
        ipAddress[i] = s[i - 1];
        totalNum = totalNum * 10 + (s[i - 1] - '0');
        i++;
    }
    if (totalNum > 255) {
        return NULL;
    }
    ipAddress[i] = '.';
    i++; /* 加完指向第9个字符(i == 8) */
    flg = 0;
    /* 写第三段 */
    totalNum = 0;
    while (i < (a + b + c + 2)) {
        if (c > 1 && s[i - 2] == '0' && flg == 0) {
            return NULL;
        }
        flg = 1;
        ipAddress[i] = s[i - 2];
        totalNum = totalNum * 10 + (s[i - 2] - '0');
        i++;
    }
    if (totalNum > 255) {
        return NULL;
    }
    ipAddress[i] = '.';
    i++; /* 加完指向第13个字符(i == 12) */
    flg = 0;
    /* 写第四段 */
    totalNum = 0;
    while (i < (a + b + c + d + 3)) {
        if (d > 1 && s[i - 3] == '0' && flg == 0) {
            return NULL;
        }
        flg = 1;
        ipAddress[i] = s[i - 3];
        totalNum = totalNum * 10 + (s[i - 3] - '0');
        i++;
    }
    if (totalNum > 255) {
        return NULL;
    }
    ipAddress[i] = '\0';
    /*输出*/
    memcpy(string, ipAddress, i + 1);
    return string;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int i = 0;
    int len = strlen(s);
    char** res = (char**)malloc(sizeof(char*) * 100);

    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                for (int d = 1; d <= 3; d++) {
                    int total = 0;
                    total = a + b + c + d;
                    if (total == len) {
                        res[i] = (char*)malloc(20);
                        memset(res[i], 0, 20);
                        res[i] = makeIPAddress(s, a, b, c, d);
                        if (res[i] == NULL) {
                            continue;
                        }
                        i++;
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    
    if (res == NULL) {
        return NULL;
    }
    *returnSize = i;
    return res;
}
```

