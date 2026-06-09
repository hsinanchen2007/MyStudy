```java
class Solution {
    public int numWays(int n) {
    int N = 1000000007;
        if (n==0)
            return 1;
        if (n==1)
            return 1;

        int a = 1;
        int b = 1;
        int c = 0;

        for (int i = 2; i <= n; i++) {
            c = (a+b)%N;
            a = b%N;
            b = c%N;
        }
        return b;
    }
}
```