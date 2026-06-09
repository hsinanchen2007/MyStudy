### 解题思路
2位数处理麻烦点，其他没有什么。

### 代码

```c
char *gBitStr[] = {"", "Thousand ", "Million ", "Billion "};
char *gNumStr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine"};
char *gOneStr[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *gTwoStr[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char * ChengeThreeNumberToWords(int num){
    char *ans = malloc(100);
    ans[0] = '\0';
    char tmp[100] = {0};
    memset(ans, 0, 100);
    if (num  / 100 > 0){
        sprintf(tmp, "%s %s ", gNumStr[num / 100], "Hundred");
        strcat(ans, tmp);
        if (num % 100 == 0){
            return ans;
        }
    }
    num %= 100;
    if (num >= 20){
        int index = num / 10;
        tmp[0] = '\0';
        sprintf(tmp, "%s ", gTwoStr[index]);
        strcat(ans, tmp);
        if (num % 10 == 0){
            return ans;
        }
    } else if (num >= 10){
        int index = num % 10;
        tmp[0] = '\0';
        sprintf(tmp, "%s ", gOneStr[index]);
        strcat(ans, tmp);
        return ans;
    }
    num %= 10;
    if (num >= 0){
        tmp[0] = '\0';
        sprintf(tmp, "%s ", gNumStr[num]);
        strcat(ans, tmp);
    }
    return ans;
}

char * numberToWords2(int num, int index){
    if (num < 1000){
        char *after = ChengeThreeNumberToWords(num);
        //printf("after:%s\n", after);
        //拼接单位
        char *ans = malloc(10000);
        ans[0] = '\0';
        strcat(ans, after);
        strcat(ans, gBitStr[index]);
        return ans;
    } else {
        //1 234 567 891
        char *res = numberToWords2(num / 1000, index + 1);
        char *ans = malloc(10000);
        ans[0] = '\0';
        strcat(ans, res);
        if (num % 1000 != 0){
            char *after = ChengeThreeNumberToWords(num % 1000);
            strcat(ans, after);
            strcat(ans, gBitStr[index]);
        }
        return ans;
    }
}
char * numberToWords(int num){
    char *ans = numberToWords2(num, 0);
    int sLen = strlen(ans);
    if (ans[sLen - 1] == ' '){
        ans[sLen - 1] = '\0';
    }
    return ans;
}

```