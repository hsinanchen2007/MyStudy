### 解题思路
    快速幂的递归写法。
    在剪绳子I的基础上，当结果很大时的处理方法。

### 代码

```cpp
class Solution {
public:
    typedef long long LL; // 使用typedef为现有类型创建别名
    int cuttingRope(int n) {
        if(n<=1) return 0;
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        else{
            // n=3*quotient+remainder  被除数=除数*商+余数  1000000007
            int quotient=n/3;
            int remainder=n%3;
            LL a=3,b,m=1000000007;
            if(remainder==0){ // pow(3,quotient);
                b=quotient;
                return f(a,b,m);
            }
            else if(remainder==1){ // pow(3,quotient-1)*4;
                b=quotient-1;
                LL tmp2=f(a,b,m);
                return tmp2*4%m;
            }
            else{ // pow(3,quotient)*2;
                b=quotient;
                LL tmp2=f(a,b,m);
                return tmp2*2%m;
            } 
        }
    }

    //快速幂的递归写法
    int f(LL a,LL b,LL m){
        if(b==1) return a%m;
        else if(b%2==0){
            LL tmp=f(a,b/2,m);
            return (tmp%m)*(tmp%m)%m; // tmp*tmp%m = (tmp%m)*(tmp%m)%m 
        }
        else{
            return f(a,b-1,m)*a%m; // f(a,b-1,m)*a%m 
        } 
    }
};
```