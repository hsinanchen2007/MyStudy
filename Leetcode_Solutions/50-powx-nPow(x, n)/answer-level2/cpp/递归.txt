```
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double ans=x;
        ans=lalala(x,x,1,abs((long long int)n));
        return n>0?ans:1.0/ans;
    }

    double lalala(double x, double ans, long long int num, long long int n){
        if(num==n)return ans;
        if(num*2<n){
            ans=lalala(x,ans*ans,num*2,n);
        }
        if(num*2>n){
            ans*=lalala(x,x,1,n-num);
        }
        if(num*2==n){
            ans=ans*ans;
        }
        return ans;
    }
};
```
