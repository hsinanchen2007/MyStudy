### 解题思路
1 动态规划进行递归推导
2 注意特殊情况，即两位数超出字符范围，或者高位数为零的场景；
3 我在本题花费时间比较长的非智力因素是：起始位置为零或者为一，没有规划好；

### 代码

```c
int getNum(int num)
{
    int n = 0;
    while (num != 0) {
        num = num / 10;
        n++;
    }
    return n;
}

void getString(int num, int n, int *pointer)
{   
    while (n) {
        pointer[n] = num % 10;
        num = num / 10;
        n--;
    }
    return;
}
#define CHAR_ARRAY_SIZE 11
int translateNum(int num){
    char *pointer = (char *)malloc(CHAR_ARRAY_SIZE * sizeof(char));
    sprintf(pointer, "%d", num);
    int n = strlen(pointer);
    int sum;
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    int i;
    int count;
    dp[0] = 1;
    dp[1] = 1;  
    sum = (pointer[0] - '0') * 10 + (pointer[1] - '0');
    if ( sum > 25 || sum < 10) {
        dp[1] = 1;
    } else {
        dp[1] = 2;
    }
    for (i = 2; i <= n; i++) {
        sum = (pointer[i - 1] - '0') * 10 + (pointer[i] - '0');
        if ( sum > 25 || sum < 10) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
            
        }
    }
    count = dp[n - 1];
    free(pointer);
    free(dp);
    pointer = NULL;
    dp = NULL;
    
    return count;
}
```