每个灯泡对应的数有多少个因子，就被开关多少次。
n轮后仍然亮着说明被开关了奇数次。
只有平方数因子数为奇数个。
所以只要求小于等于n的平方数的个数
```C++ []
class Solution {
public:
    int bulbSwitch(int n) {
        int cnt=1;
        while(cnt*cnt<=n){
            cnt++;
        }
        return cnt-1;
    }
};
```
