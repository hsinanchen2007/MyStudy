### 解题思路
java 执行用时 :
0 ms

### 代码

```java
class Solution {
    public int fib(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        for (int i = 0; i < n - 1; i++) {
               //2+3=5  3+5=8
            int result=first+second;
            first=second;
            second=result;
        }
        return second;
    }
}
```