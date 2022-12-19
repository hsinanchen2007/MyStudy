### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    long long abc(int x,int y){
        int tmp=(int)1e9+7;
        long long res=1;
        while(x){
            res*=x--;
            res%=tmp;
        }
        while(y){
            res*=y--;
            res%=tmp;
        }
        return res;
    }
    bool zhishu(int n){
        if(n==1)return false;
        for(int i=2;i<=sqrt(n);++i){
            if(n%i==0)return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int count=0;
        for(int i=1;i<=n;++i){
            if(zhishu(i)){
                ++count;
            }
        }
        return abc(count,n-count);
    }
};
```