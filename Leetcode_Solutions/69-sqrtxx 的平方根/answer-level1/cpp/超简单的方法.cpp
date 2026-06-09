```
class Solution {
public:
    int mySqrt(int x) {
        int ans=1;
        long long temp = 1;//解决超过int范围
        while(temp * temp <= x){
            ans++;
            temp++;
        }
        return ans-1;
    }
};
```
