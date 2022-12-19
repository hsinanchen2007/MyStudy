注意要取模。
(a + b) % p = (a % p + b % p) % p
```
class Solution {
    public int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a=0, b=1, c=0;
        while(n>=2){
            c=a%1000000007+b%1000000007;
            a=b;
            b=c;
            n--;
        }
        return c%1000000007;
    }
}
```
![image.png](https://pic.leetcode-cn.com/2e248a6878151a2d8f4f48fa1d64f47fb7f2eef15f32051dec10ff7febce61d5-image.png)
