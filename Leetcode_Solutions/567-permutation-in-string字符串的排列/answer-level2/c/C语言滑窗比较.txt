### 解题思路
1. 方法一 用数组hash思想，memcpy比较字母个数
2. 方法二 对每个字符串排序，在strcmp比较字符序列是否一致，性能不行，超时

### 代码

```c
/*  方法一：将字母个数保存到数组里，最后memcpy 数组对应的内存是否一致来确定是否存在序列 */
#define ALP_NUM_MAX   26
bool checkInclusion(char * s1, char * s2){
    int len1, len2;
    int alp_len1[ALP_NUM_MAX] = {0};
    int alp_len2[ALP_NUM_MAX] = {0};
    int i, j;

    len1 = strlen(s1);
    len2 = strlen(s2);

    if (len2 < len1) {
        return false;
    }

    for (i = 0; i < len1; i++) {
        alp_len1[s1[i] - 'a']++;
        alp_len2[s2[i] - 'a']++; /* s2起始的字母个数 */
    }

    if (memcmp(alp_len1, alp_len2, sizeof(int) * ALP_NUM_MAX) == 0) {
        return true;
    }

    for (i = 1; i <= (len2 - len1); i++) {  
        alp_len2[s2[i - 1] - 'a']--;
        alp_len2[s2[i + len1 -1] - 'a']++;

        if (memcmp(alp_len1, alp_len2, sizeof(int) * ALP_NUM_MAX) == 0) {
            return true;
        }
    }

    return false;  
}

/* 方法二  strcmp 前提是要先给字符排序，qsort会导致性能变差，用例超时*/
#if 0
int comp(const void *a,const void *b)
{
    return (*(char *)a - *(char *)b);
}

bool checkInclusion(char * s1, char * s2){
    int len1, len2;
    int cnt = 0;
    char* substr = NULL;
    char* clone = NULL;
    int i;

    len1 = strlen(s1);
    len2 = strlen(s2);

    if (len2 < len1) {
        return false;
    }

    /* substr用来跟s1进行比较 */
    substr = malloc((len1 + 1) * sizeof(char));
    for (i = 0; i < len1; i++) {
        substr[i] = '0';
    }

    qsort(s1, len1, sizeof(char), comp);

    while (*s2 != '\0') {
        if ((len2 - cnt) < len1) {
            return false;
        }
        memcpy(substr, s2, len1);
        substr[len1] = '\0';

        qsort(substr, len1, sizeof(char), comp);

        if (strcmp(substr, s1) == 0) {
            return true;
        }

        s2++;
        cnt++;
    }

    return false;
}

#endif