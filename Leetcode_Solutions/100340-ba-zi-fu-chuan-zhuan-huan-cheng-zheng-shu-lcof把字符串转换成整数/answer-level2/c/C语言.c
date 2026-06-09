### 解题思路
见招拆招，照要求做判断即可。
筛选条件加来加去被我搞得挺丑陋的。

### 代码

```c
int strToInt(char* str){
    int i = 0, syn = 1, j = 0, flag = 0 ,flag2 = 0;//flag判断字符串中的0是否为无效0；flag2判断数字是否已经开始；
    long long int num = 0;//用long long int储存可能越界的数据
    while(str[i] == 32 || str[i] == 9 || str[i] == 48 || str[i]== 45 || str[i]== 43){
        //这个循环用来跳过开头的无意义字符（如空格，0），并获取符号。下方内容为符号的获取。
        if (str[i] == 45 && flag2 == 0){
            syn = -1;
            flag2 = 1;
        }
        if (str[i] == 43 && flag2 == 0){
            syn = 1;
            flag2 = 1;
        }
        if(str[i] >= 48 && str[i] <= 57 && flag2 == 0){
            syn = 1;
            flag2 = 1;
            num = num * 10 + str[i] - 48;
            if(str[i] == 48){
                j--;
            }else{
                flag = 1;
            }
            j++;
        }
        i++;
        if ((str[i] == 43 && flag2 == 1) || (str[i] == 45 && flag2 == 1) || ((str[i] < 48 || str[i] > 57) && flag2 == 1)) return 0;
    }
    


    while(str[i] >= 48 && str[i] <= 57){
        num = num * 10 + str[i] - 48;
        if(str[i] < 48 && str[i] > 57 && flag2 == 1){
            return 0;
        }
        if(flag == 0){
            if(str[i] == 48){
                continue;
            }else{
                flag = 1;
            }
        }
        i++;j++;
        if(j>10 && syn == -1){
            return INT_MIN;
            break;
        }else if(j>10 && syn == 1){
            return INT_MAX;
            break;
        }
    }

    if (num * syn >= INT_MAX){
        return INT_MAX;
    }else if(num * syn <= INT_MIN){
        return INT_MIN;
    }
    return num * syn;
}
```