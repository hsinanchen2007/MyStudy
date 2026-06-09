### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int N) {
        int a = 0,b = 1,sum;
        for(int i=0;i<N;i++){
            sum  = a + b;
            a = b;
            b = sum;
        }
        return a;
    }
}
```