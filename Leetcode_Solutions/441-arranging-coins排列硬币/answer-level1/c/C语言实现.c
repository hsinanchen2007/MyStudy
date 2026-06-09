方法一：公式法直接用double型的开根号公式
```C []
int arrangeCoins(int n){
    return (int)((sqrt(8.0 * n + 1) - 1) / 2);
}
```
方法一：公式法直接用int型的开根号公式
```C []
int arrangeCoins(int n){
    int row = (int)(sqrt(2) * sqrt(n));
    int cmp = (row & 1) ? (row * ((row + 1) >> 1)) : ((row >> 1) * (row + 1));
    return (n < cmp) ? --row : row;
}
```
