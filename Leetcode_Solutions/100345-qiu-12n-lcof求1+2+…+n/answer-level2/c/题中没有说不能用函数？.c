### 解题思路
指数函数&位运算变相实现 `n(n + 1)/2`

### 代码

```c
int sumNums(int n){
    return (int)pow(n, 2) + n >> 1;
}
```