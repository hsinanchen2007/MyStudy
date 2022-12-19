```
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }        
        double ans = 1;
        double half = x;
        while (N) {
            if (N & 1) {
                ans = ans * half;
            }
            half = half * half;            
            N >>= 1;
        }
        return ans;
    }
```

![image.png](https://pic.leetcode-cn.com/63c607d861705eb54c27e232992742d45e96db5ecbe064435d1aecdd207d20a8-image.png)


从基本原理到代码运行有一个转换过程，不少讲解忽略了这一部分，我刚看代码的时候也是迷迷糊糊。索性写了一个运行过程，让大家更直观的感受到代码和原理的联系。