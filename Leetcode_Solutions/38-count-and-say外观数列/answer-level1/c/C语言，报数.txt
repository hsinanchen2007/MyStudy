思路：模拟报数过程

1. 对 res 字符串的每位字符进行报数，每轮计数结果为 count 个 c
2. 将本轮计数结果 count，c 存入字符串 tmp
3. 报数完毕后，更新 res，使等于 tmp
4. 重复 1~3 直到满足要求的轮次

```C
char * countAndSay(int n){
    char *res = (char*)malloc(sizeof(char) * 5000);
    char *tmp = (char*)malloc(sizeof(char) * 5000);
    res[0] = '1'; res[1] = '\0';     // res 初始化为 "1"
    int len = 1;                     // len 为 res 的有效长度
    while (--n) {
        int i = 0, j = 0;
        while(i < len) {             // 对 res 的每位字符 c 进行报数
            int count = 1;
            char c = res[i++];
            while (i < len && res[i] == c)    // 计算本轮报数结果，即本轮有几个 c
                i++,count++;
            tmp[j++] = count + '0';           // 将报数结果存入 tmp
            tmp[j++] = c;
        }
        tmp[j] = '\0';
        strcpy(res, tmp);                     // 将 tmp 复制到 res，并更新 res 长度
        len = j;
    }
    return res;
}
```