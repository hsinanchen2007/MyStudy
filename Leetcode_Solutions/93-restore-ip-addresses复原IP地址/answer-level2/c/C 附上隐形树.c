![捕获.JPG](https://pic.leetcode-cn.com/8d5bb6f3f210c22222920df5b02c43c1c94e8c1cf76c75634a39ada678af98c6-%E6%8D%95%E8%8E%B7.JPG)


````
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024

bool isValid(char *s, int len) {
    if (s == '\0') {
        return false;
    }
    
    if (s[0] == '0' && len > 1) {
        return false;
    }
    // 将字符串转换成数字
    // num += num*10 - (s[i] -'0')
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + s[i] - '0';
    }
    // 判断每个IP字段有效性
    if (num >= 0 && num <= 255) {
        return true;
    }
    // printf("*********** num=%d, len=%d\r\n", num, len);
    return false;
}

void BackTrace(char *s, char **res, int *returnSize, char *str, int idx, int validNum)
{
    if (validNum > 4) {
        return;
    }
    if (s[0] == '\0' && validNum == 4) { // 匹配完了
        res[*returnSize] = (char *)malloc(strlen(str) + 1);
        strcpy(res[*returnSize], str);
        (*returnSize)++;
    }
    // 添加点隔离符
    if (validNum > 0 && validNum < 4) {
        str[idx++] = '.';
    }

    for (int len = 1; len <= 3 && len <= strlen(s); len++) {
        
        if (isValid(s, len)) {            
            for (int i = 0; i < len; i++) {
                str[idx + i] = s[i];
            }
            // 非常有必要加上结束符 否则后面打印会有误导
            str[idx + len] = '\0'; 
            // printf("str=%s, len=%d, validNum=%d, s=%s\r\n", str, len, validNum, s);
            BackTrace(s + len, res, returnSize, str, idx + len, validNum + 1);
        }
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    char **res = (char **)malloc(MAX_SIZE * sizeof(char *));
    *returnSize = 0;
    char *str = (char *)calloc(strlen(s) + 4, sizeof(char));
    BackTrace(s, res, returnSize, str, 0, 0);
    return res;    
}`
```
