### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int N) {
        
        if (N == 0) return 0;

        int a = 0; // N == 0
        int b = 1; // N == 1
        int res = b;
        int i = 1;
        while (i<N){
            res = a + b;
            a = b;
            b = res;
            i++;
        }
        return res;
    }
}
```