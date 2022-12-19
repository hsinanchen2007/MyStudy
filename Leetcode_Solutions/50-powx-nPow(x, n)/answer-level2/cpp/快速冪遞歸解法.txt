### 解题思路
遞歸解法，注意點：
1.負數情況下如果直接使用int會溢出報錯，需要使用long N=n;來存儲n的值
2.因爲整數除法原因，分奇數偶數兩種情況討論遞歸的值。
### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        else if(n>0){
            if(n&1) return myPow(x*x,n/2)*x;
            else return myPow(x*x,n/2);//是偶數
        }else{//n<0
            long N=n;
            N= -N;
            if(N&1) return 1.0/(myPow(x*x,N/2)*x);
            else return 1.0/myPow(x*x,N/2);//是偶數
        };
    };
};
```