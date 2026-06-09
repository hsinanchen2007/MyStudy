### 解题思路
菜鸟一个，不会高级的，盘就完了，跟他死磕，有多少种输入就设几个判断。

### 代码

```c
int myAtoi(char * str){

    long long returnNum = 0;
    int bz = 0;
    int bz1 = 0;
    int bz2 = 0;
    int num[20] = {0};
    int n = 0;
    long long  p = 1;
    for(int i = 0 ;str[i] != '\0'; i++)
    {
        if(bz == 1 && (str[i] > '9' || str[i] < '0'))break;
        if(bz == 2 && (str[i] > '9' || str[i] < '0'))break;
        if(bz == 0 && (str[i] > '9' || str[i] < '0') && (str[i] != '+' && str[i] != '-' && str[i] != ' '))break;
        if(bz == 0)
        {
            if(str[i] == '-') bz = 1;
            else if(str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) bz = 2;
        }
        if(bz != 0 && str[i] != '0' && str[i] != '+' && str[i] != '-') bz1= 1;
        if((str[i] > '9' || str[i] < '0') && (str[i] != '+' && str[i] != '-') && bz1 != 0)break;
        //if((n == 9 && num[0] >2 && num[1] > 1) || n > 9) return -2147483648;
        if(n > 9) 
        {
            if(bz == 1) return -2147483648;
            if(bz == 2) return 2147483647;
        }
        if(bz1 != 0)
        {
            num[n] = str[i] - '0'; n++;
        }
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(bz == 1)
        {
            returnNum -= num[i] * p;
        }
        else if(bz == 2)
        {
            returnNum += num[i] * p;
        }
        p *= 10;
    }
    if(returnNum > 2147483647) return 2147483647;
    else if(returnNum < -2147483648) return -2147483648;
    return returnNum;
}
```