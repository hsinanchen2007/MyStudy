### 解题思路
思路比较简单，注意边界值
### 代码

int reverse(int x){
    int out = 0;
    int count = 0;
    int flag = 0;

    if(x >= 0){
        flag = 1;
    }

    while(x != 0){
        if((out <= 214748364 || out > -214748364) && x != 0 && count == 9){
            if((flag && x >7) ||(flag == 0) && x > 8){
                return 0;
            }
        }
        if(out > 214748364 || out < -214748364){
            return 0;
        }
        out = out*10;
        out = out + x % 10;
        x = x/10;
        count++;
    }

    return out;
}
```