感觉取模很坑啊...
```java
class Solution {
    public int fib(int n) {
        if(n<=1)
            return n;
        int a=0, b=1, res=-1;
        for(int i=2; i<=n; i++){            
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }
        return res;
    }
}
```