fib(n) = fib(n-1)+fib(n-2)
只需记住前两项即可求解fib(n)
```
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int a = 0;
        int b = 1;
        while(--n){
            int c = (a + b)%1000000007;//c计算fib(n)，注意取模
            a = b; //a记录下一项的fib(n-2)
            b = c; //b记录下一项的fib(n-1)（即本项，所以返回b）
        }
        return b;
    }
};
```
