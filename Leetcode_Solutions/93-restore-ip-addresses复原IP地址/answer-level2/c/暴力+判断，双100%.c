### 解题思路
此处撰写解题思路
每个字段三个字节三次循环，每取一个字段进行合法判断，合法继续下一个字段，不合法继续下一次循环
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool IsValied(char * s)
{
    if (strlen(s) > 1 && s[0] == '0')
    {
        return false;
    }
    int num = atoi(s);
    if (num < 0 || num > 255) {
        return false;
    }
    return true;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    *returnSize = 0;
    if (s == NULL || returnSize == NULL) {
        return NULL;
    }
    int len = strlen(s);
    if (len < 4 || len > 12) {
        return NULL;
    }

    char ** retStr = (char **)malloc(sizeof(char *) * 100);
    int retLen = 0;

    for (int i = 0; i < 3; i++) {
        char str1[12] = {0};
        strncpy(str1, s , i + 1);
        if (!IsValied((char *)str1)) {
            continue;
        }
        for (int j = 0; j < 3 && i + j + 2 < len; j++) {
            char str2[12] = {0};
            strncpy(str2, s + i + 1, j + 1);
            if (!IsValied((char *)str2)) {
                continue;
            }
            for (int k = 0; k < 3 && i + j + k + 3 < len; k++) {
                char str3[12] = {0};
                strncpy(str3, s + i + j + 2, k + 1);
                if (!IsValied((char *)str3)) {
                    continue;
                }
                char str4[12] = {0};
                strcpy(str4, s + i + j + k + 3);
                if (!IsValied((char *)str4)) {
                    continue;
                }
                char *out = malloc(sizeof(char) * 20);
                memset(out, 0, 20);
                sprintf(out, "%s.%s.%s.%s",str1, str2, str3, str4);
                retStr[retLen] = out;
                retLen++;
            }
        }
    }
    *returnSize = retLen;
    return retStr;
}
```