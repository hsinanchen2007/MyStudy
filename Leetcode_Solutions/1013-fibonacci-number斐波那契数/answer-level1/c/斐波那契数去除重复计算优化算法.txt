### 解题思路
此处撰写解题思路
简单来说，就是先按前后循序求解，然后去除重复计算就OK了
### 代码

```c
int fib(int N){
    int a = 0, b = 1;
    int l1,l2;  //使用两个变量储存中间结果，避免重复计算
    if (N == 0) return 0;
    if (N == 1) return 1;
    if (N == 2) return 1;
    if (N == 3) return 2;
    if (N % 2 == 0) {
        l1 = b;
        b = a + b;
        for (int i = 1; i <= (N - 2)/2; i++) {
            l2 = b;
            b = l1 + b;
            l1 = b;
            b = l2 + b;
        }
        return b;
    }
    else {
        l1 = b;
        b = a + b;
        l2 = b;
        b = l1 + b;
        for (int i = 1; i <= (N - 3)/2; i++) {
            l1 = b;
            b = l2 + b;
            l2 = b;
            b = l1 + b;
        }
        return b;
    }
}
```