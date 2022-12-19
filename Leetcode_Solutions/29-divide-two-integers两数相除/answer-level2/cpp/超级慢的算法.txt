### 解题思路
先使用成倍累加，再逐步累加
### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)return INT_MAX;
        if(divisor==1)return dividend;
        if(divisor==-1){
            if(dividend==INT_MIN)return INT_MAX;
            else return 0-dividend;
        }
        if(dividend==divisor)return 1;
        if(divisor==INT_MIN||dividend==0)return 0;
        else {
            bool f;
            int s=1,divisor_t=divisor;
            if((dividend<0&&divisor<0)||(dividend>0&&divisor>0))f=1;//商的符号位
            else f=0;
            if(dividend>0)dividend=0-dividend;//全部转换为负数进行运算
            if(divisor>0){divisor=0-divisor;divisor_t=0-divisor_t;}
            if(divisor<dividend)return 0;
            if(divisor==dividend)s=1;
            while(dividend<divisor){               
                if(divisor>=INT_MIN-divisor){s=s<<1;divisor+=divisor;}
                else break;
            }
            if(divisor<dividend){
                while(divisor<dividend){
                s--;
                divisor=divisor-divisor_t;
                }
            }
            else if(divisor>dividend){
                while(divisor>=dividend){
                if(divisor>=INT_MIN-divisor_t){s++;divisor+=divisor_t;}
                else break;
                }
                if(divisor<dividend)s--;
                //s--;
            }
            if(!f)return 0-s;
            else return s;
        }
    }
};
```