### 解题思路
循坏，每次总数减去行数，总数不足的时候返回 行数-1

### 代码

```c
int arrangeCoins(int n){
    for(int i=1;n>=0;++i)
        if(n-i<0)
            return i-1;
        else
            n-=i;
    return 0;
}
```