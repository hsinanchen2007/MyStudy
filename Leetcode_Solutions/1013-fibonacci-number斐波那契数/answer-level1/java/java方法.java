```
class Solution {
    public int fib(int N) {
        int a = 0, b =1;
        if(N < 2) return N;

        for(int i = 2; i <= N; i++) {
            a = (b += a) - a;
        }
        return b;
    }
}
```
