```
class Solution {
public:
    int fib(int N) {
        int p1 = 1;
        int p2 = 0;
        int f = 0;
        if(N<2)
            return N;
        for(int i=0; i<N-1; i++)
        {
            f = p1+p2;
            p2 = p1;
            p1 = f;
        }
        return f;
    }
};
```
