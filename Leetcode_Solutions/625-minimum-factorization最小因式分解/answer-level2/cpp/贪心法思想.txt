### 解题思路
贪心法的思想，每次在2-9中找最大的因子，最后一个push进去的必然是最小的因子，只需把这些因子倒序连接即可。

### 代码

```cpp
class Solution {
public:
    int smallestFactorization(int a) {
        //a=18000000;
        if(a<=0) return 0;
        if(a<10) return a;
        vector<int> yinzi;
        int i;
        while(a!=1){
            for(i=9;i>=2;i--){
                if(a%i==0){
                    yinzi.push_back(i);
                    a/=i;
                    break;
                }
            }
            if(i==1) return 0;
        }
        long long result=0;
        for(i=yinzi.size()-1;i>=0;i--){
            result=result*10+yinzi[i];
            if(result>INT_MAX) return 0;
        }
        return result;
    }
};
```