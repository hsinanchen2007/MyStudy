### 解题思路
此处撰写解题思路

### 代码

```c
int climbStairs(int n){
    int a = 1;
    int b = 2;
    int sum = 0, i = 0;
    if(n <= 2) {
        return n;
    }
    for (i = 2; i < n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}
```