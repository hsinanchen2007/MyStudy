### 解题思路


### 代码

```c
int myAtoi(char * str){
    int len = 0;
    int find = 0;
    int retNum = 0;
    int vaild = 0;
    if (str == NULL) {
        return 0;
    }
    len = strlen(str);

    for (int i = 0; i < len; i++) {
        //printf("check %c\r\n",str[i]);
        if (find == 0) {
            if(str[i] == ' ') {
                //printf("check blank %c\r\n",str[i]);
                continue;
            }
            if((str[i] > '9' || str[i] < '0')) {
               // printf("check word1 %c\r\n",str[i]);
                if((str[i] != '-' && str[i] != '+')){                    
                    return 0;
                }
            }
        }
        if (find != 0) {
            //printf("check vaild %c,ret %d\r\n",str[i],retNum);
            if((str[i] > '9' || str[i] < '0')) {               
                break;
            }
        }
  
        if ((str[i] == '+' || str[i] == '-') && find != 0)
            return 0;
        if (str[i] == '-' && !find) {
            find = 1;// 1表示负数
        }
        if (str[i] == '+' && !find) {
            find = 2;// 2表示正数
        }
        if (str[i] <= '9' && str[i] >= '0') {
            // 处理数字
            if (!find) {
                find = 2;
            }
            //printf("check num %c ret %d find %d\r\n",str[i], retNum, find);
            if(find == 2 ) {
                if (retNum > 214748364) {
                    retNum = 2147483647;
                    return retNum;
                }
                if (retNum == 214748364 &&  (str[i] - '0') > 7) {
                    retNum = 2147483647;
                    return retNum;
                }
            }
             if(find == 1 ) {
                if (retNum > 214748364) {
                    retNum = -2147483648;
                    return retNum;
                }
                if (retNum == 214748364 &&  (str[i] - '0') >= 8) {
                    retNum = -2147483648;
                    return retNum;
                }
            }
            retNum = retNum * 10 + (str[i] - '0');
        }
    }
    return ((find == 1) && (find != 0))? (0 - retNum) : retNum;
}
```