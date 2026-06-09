```
class Solution {
    public int fib(int N) {
        int count = 0;
        int a = 0;
        int b = 1;
        while(count++ < N){
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
}
```
