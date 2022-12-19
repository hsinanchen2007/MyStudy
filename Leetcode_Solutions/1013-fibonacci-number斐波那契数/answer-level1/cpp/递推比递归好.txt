```
class Solution {
public:
    int fib(int N) {
        if(N<=1)
            return N;
        int f1 = 0, f2 = 1, f = 0;
        int i = 2;
        while(i<=N)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
            i++;
        }
        return f;
    }
};