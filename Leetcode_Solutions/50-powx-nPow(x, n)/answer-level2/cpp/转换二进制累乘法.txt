### 解题思路
将n转换为二进制，通过累乘减少计算

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        int flag=true;
        if(n==-pow(2,31))   return(1/(myPow(x,pow(2,31)-1)*x));
        if(n<0) {n=-n;flag=false;}
        vector<int> bin;
        while(n>0){
            bin.push_back(n%2);
            n/=2;
        }
        int l=bin.size();
        double ans=1,tmp;
        for(int i=0;i<l;++i){
            if(bin[i]==1){
                tmp=x;
                for(int j=0;j<i;++j) {tmp=tmp*tmp;}
                ans*=tmp;
            }
        }
        return flag?ans:1/ans;
    }
};
```