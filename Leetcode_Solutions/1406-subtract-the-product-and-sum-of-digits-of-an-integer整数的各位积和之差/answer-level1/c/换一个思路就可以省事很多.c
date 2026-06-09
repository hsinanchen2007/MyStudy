### 解题思路
逐位计算
### 代码

```c


int subtractProductAndSum(int n){
    int mul,sum,temp;
    mul = 1;
    sum = 0;
    while(n > 0){
        temp = n % 10;
        n /= 10;
        mul *= temp;
        sum += temp;
    }
    return ((mul) - (sum));
}


```