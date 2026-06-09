### 解题思路
用等差数列求和公式求出最大的n即可

### 代码

```c
int arrangeCoins(int n){
    for(long i=0;;i++)
    {
        if(((i*(i+1))/2)<=(long)n&&(((i+1)*(i+2))/2)>(long)n)
            return (int)i;
    }

}
```