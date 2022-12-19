```
/**
 * "ab1d"
 *  while 循环单词
 * 
 *  首字母大小
 *    |
 *   "ab1d"  ["ab1d", "Ab1d"]
 *
 *   非首字符，判断字符是否是字母，如果是则将数组中的元素拷贝一份，并将对应该的字母更大小写
 *     |
 *   "ab1d"  ["ab1d", "Ab1d", "aB1d", "AB1d"]
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize){
 
    int count = 1;
    int len = 0;
    char *p = S;
 
    while(*p != '\0') {
        len++;
        count *= ((*p >= '0' && *p <= '9') ? 1 : 2);
        p++;
    }
    // for extract space for '\0'
    len++;
    
    *returnSize = count;
    
    p = S;   
    char * * sp = malloc(sizeof(char *) * count);
    if(*S == '\0') {
        *returnSize = count;
        *sp = "";
        return sp;
    }
    char * * s = sp;
    int i, j, m, n;
    i = j = m = n = 0;
    int mask = 1 << 5;
    while( *p != '\0') {
        if (i==0) {
            char * str = malloc(sizeof(char) * len);
            memcpy(str, S, len);
            *sp++ = str;
            j++;
            if(*p < '0' || *p >'9') {
                char * str = malloc(sizeof(char) * len);
                memcpy(str, S, len);           
                str[i] ^= mask;
                *sp++ = str;
                j++;
            }
        } else {
            n = j;
            if(*p < '0' || *p > '9') {
                for(m = 0; m < n; m++) {
                    char * str = malloc(sizeof(char) * len);
                    memcpy(str, s[m], len);
                    str[i] ^= mask;
                    *sp++ = str;
                    j++;
                }
            }
        }
        p++;
        i++;
    }
    return s;
}
```