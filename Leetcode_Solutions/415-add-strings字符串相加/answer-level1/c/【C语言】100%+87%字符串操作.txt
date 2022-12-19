### 解题思路
1.思路比较简单：利用字符对应的ASCII码进行加和，并记录进位值。
2.corner condition：
（1）.两数位数相同时，如何处理进位；
3.经验教训：没有遇到什么特别的问题；
4.耗时：64mins，花的时间太长了，哎~~。主要耗时点：
（1）字符串返回时，把‘\0’放在了前面，导致返回时打印为空，逐行加打印定位根因，耗时太长-----定位根因时应该反过来，从后往前加打印；
（2）两数位数相同时，未考虑到这个ecorner condition------边界条件考虑不足；
（3）字符串操作不熟练。-----字符串逆序处理时思路过于复杂，未能借助空间的优势来做。

![image.png](https://pic.leetcode-cn.com/7c6ecca68cc95044ded8059bb240f8a208f890f2a5ea80d762ada36fb57b1169-image.png)


### 代码

```c
#define MAX 5200
char * addStrings(char * num1, char * num2){
    int len1 = 0;
    int len2 = 0;
    int retlen = 0;
    int maxlen = 0;
    int minlen = 0;
    int i = 0;
    int jinwei = 0;
    int temp = 0;
    char ret[MAX] = {'\0'};
    char *end = NULL;
    len1 = strlen(num1);
    len2 = strlen(num2);
    maxlen = len1 > len2 ? len1 : len2;
    minlen = len1 < len2 ? len1 : len2;

    // printfprintfprintf("maxlen = %d, minlen = %d\n",maxlen, minlen);

    for(i = 0; i < maxlen; i++) {
        if(minlen - 1 - i >= 0) {
            // printf("(num1[%d - 1 - %d] - \'0\') = %d, (num2[%d - 1 - %d] - \'0\' = %d ",len1, i , (num1[len1 - 1 - i] - '0'), len2, i, (num2[len2 - 1 - i] - '0'));
            temp = jinwei + (num1[len1 - 1 - i] - '0') + (num2[len2 - 1 - i] - '0');
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            // printf("temp = %d, jinwei = %d\n", temp, jinwei);
            ret[i] = (char)('0' + temp);
            // printf(" ret[%d] = %c\n", i, ret[i]);
        }
        else if(minlen == len2){
            // printf("comehere\n");
            temp = jinwei + (num1[len1 - 1 - i] - '0') + 0;
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            ret[i] = (char)('0' + temp);            
        }
        else if(minlen == len1){
            temp = jinwei + 0 + (num2[len2 - 1 - i] - '0');
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            ret[i] = (char)('0' + temp);            
        }    
    }

    if(jinwei != 0) {
        ret[i] = (char)('0' + jinwei);   
        jinwei = 0;
    }

    retlen = strlen(ret);

    end = (char *)malloc((retlen + 1) * sizeof(char));
    memset(end, '\0', (retlen + 1) * sizeof(char));

    for(i = 0; i < retlen; i++) {
        end[retlen - 1 - i] = ret[i];
    }
    // for(i = 0; i < retlen; i++) {
    //    printf("%c",end[i]);
    // }
    // printf("end = %s\n", end);
    return end;
}
```