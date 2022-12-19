### 解题思路
暴力美学
1、先判断4个字符串长度是否为3位数及以下，如果不是不符合；
2、将字符串转换为数字是否小于等于255，
3、需要特殊处理3位数或者2位数开头为0的情况（比如：010，这种就不符合题目要求，需要去掉）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isOK(char *str)
{
    int len = strlen(str);
    int sum = 0;
    if (len > 1 && str[0] == '0') {
        return false;
    }
    if (len == 3) {
        sum = 100 * (str[0] - '0') + 10 * (str[1] - '0') + (str[2] - '0');
    } else if (len == 2) {
        sum = 10 * (str[0] - '0') + (str[1] - '0');
    } else if (len == 1) {
        sum = (str[0] - '0');
    }
    if (sum <= 255) { 
        return true;
    }
    return false;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    if (s == NULL || strlen(s) < 4 || strlen(s) > 12) {
        *returnSize = 0;
        return NULL;
    }
    
    char **ret = (char **)malloc(sizeof(char *) * 100);
    int i,j,k;
    int count = 0;
    int len = strlen(s);
    for (i = 0; i < 100; i++) {
        ret[i] = (char *)malloc(sizeof(char) * 20);
        memset(ret[i], 0, sizeof(char) * 20);
    }
    char *str1 = (char *)malloc(sizeof(char) * 10);
    char *str2 = (char *)malloc(sizeof(char) * 10);
    char *str3 = (char *)malloc(sizeof(char) * 10);
    char *str4 = (char *)malloc(sizeof(char) * 10);

    for (i = 0; i < 3; i++){
        memset(str1, 0, sizeof(char) * 10);
        strncpy(str1, s, i + 1);
        for (j = 0; j < 3; j++) {
            if (i + 1 + j + 1 < len) {
                memset(str2, 0, sizeof(char) * 10);
                strncpy(str2, s + i + 1, j + 1);
                for (k = 0; k < 3; k++) {
                    if (i + 1 + j + 1 + k + 1 < len) {
                        memset(str3, 0, sizeof(char) * 10);
                        strncpy(str3, s + i + 1 + j + 1, k + 1);
                        if (i + 1 + j + 1 + k + 1 + 3 >= len) {
                            memset(str4, 0, sizeof(char) * 10);
                            strcpy(str4, s + i + 1 + j + 1 + k + 1); 
                            //printf("str1 = %s, str2 = %s, str3 = %s, str4 = %s\n", str1,str2,str3,str4);
                            if (isOK(str1) && isOK(str2) && isOK(str3) && isOK(str4)) {
                                sprintf(ret[count++], "%s.%s.%s.%s", str1,str2,str3,str4);
                            }
                        }
                    }   
                }
            }
            
        }
    }

    //printf("count = %d\n",count);
    *returnSize = count;
    return ret;
}
```