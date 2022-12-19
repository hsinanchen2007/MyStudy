### 解题思路
此处撰写解题思路

### 代码

```c
int newDigit(int n){
    int sum = 0;
    int tmp = 0;

    while(n != 0){
        tmp = n%10;
        sum = sum + tmp*tmp;
        n = n/10;
    }

    return sum;
}

bool isHappy(int n){
    int digit[30000] = {0};
    int num = 0;
    int i = 0;

    digit[0] = n;
    while(digit[num] != 1){
        digit[++num] = newDigit(digit[num]);
        for (i=0; i<num; i++){
            if (digit[num] == digit[i]){
                return false;
            }
        }
    }
    
    return true;
}
```