
```
class Solution {
    public int fib(int N) {
        int l = 0,r = 1;
        for (int i=0;i<N;i+=2){
            l += r;
            r += l;
        }
        return (N&1)==0?l:r-l;
    }
}
```
