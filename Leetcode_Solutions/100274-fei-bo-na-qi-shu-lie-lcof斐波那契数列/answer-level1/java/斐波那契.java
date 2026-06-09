### 解题思路
此处撰写解题思路
在计算的过程中就需要对结果去模，否则有可能超出int的范围
### 代码

```java
class Solution {
    public int fib(int n) {
        if(n <= 1)
            return n;
        int f0 = 0, f1 = 1, f2 = 0;
        for(int i = 2; i <= n; i++){
            f2 = f0 + f1;
            if(f2 >= 1000000007)
                f2 %= 1000000007;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
}
```