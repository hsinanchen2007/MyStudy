### 解题思路
一个for循环 即可

### 代码

```c
int tribonacci(int n) {
    int a = 0 , b = 1 , c = 1 ;
    int x = 1, i ;
    if (n < 2) {
        return n;
    }
    for (i = 2 ; i < n ; i++) {
        x = a + b + c ;
        a = b ; 
        b = c ;
        c = x ;
    }
    return x ;
}
```