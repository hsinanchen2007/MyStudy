我们都知道ab<=(a+b/2)^2,当且仅当a=b时，取到最大值；
同样推广到n个数，即n个数相等时，取到最大值；
对于分成的a段绳子，若n%a==0，最大值为pow（n/a, a）
                  若n%a！=0，则参照上述思想，应该让每段绳子长度尽可能相等，例如10分成四段，则2*2*3*3 = 36, 
                                                                                         2*2*2*4 = 32。
并且分成的a段绳子从2,3,4...n，的过程中，其乘积值可以理解为组合C的过程，即是一个凸函数，其函数值必定先增大后减小（可能会有不变的点）
```
class Solution {
public:
    int cuttingRope(int n) {
        int ans = 0;
        for(int i=2; i<=n; i++){
            int a = n/i, b = n%i;
            int temp = pow(a, i-b)*pow(a+1, b);
            if(ans<temp) ans = temp;
            else break;
        }
        return ans;
    }
};
```

