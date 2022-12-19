```java
class Solution {
    public int numWays(int n) {
        if(n==0)
            return 1;
        if(n<=2)
            return n;
        int a = 1, b = 2, res = -1;
        for(int i=3; i<=n; i++){
            res = (a+b)%1000000007;
            a = b;
            b = res;
        }
        return res;
    }
}
```