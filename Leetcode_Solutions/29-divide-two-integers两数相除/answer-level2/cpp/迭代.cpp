### 解题思路
c++真恶心，不用long判断条件一堆，只有tmp参数上用long节省时间

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        //排除 除数=0 的情况
        if(divisor==0)
            return INT_MAX;
        //排除 除数=1 的情况
        if(divisor==1)
            return dividend;
        //排除 除数=被除数 的情况
        if(dividend==divisor)
            return 1;
        //排除 除数=-1 的情况
        if(divisor==-1){
            if(dividend>=0)
                return -dividend;
            else if(dividend>INT_MIN)
                return dividend;
            else
                return INT_MAX;
        }
        //若 除数=INT_MIN, 且前面排除了 除数=被除数 的情况，因此条件下计算均为0
        if(divisor==INT_MIN)
            return 0;
        
        int addCout = 0;
        
        bool flag = false;
        if((dividend>0 && divisor>0)||(dividend<0 && divisor<0))
            flag = true;
        
        if(dividend == INT_MIN){
            dividend += abs(divisor);
            addCout = 1;
        }
      
        int dend = abs(dividend);
        int sor = abs(divisor);

        int Cout = 0;

        if(dend<sor){
            Cout = 0;
        }
        else{
            while(dend>=sor){
                long tmp = sor;
                int bCout = 1;
                while((tmp+tmp)<dend){
                    tmp = tmp + tmp;
                    bCout = bCout + bCout;
                }
                dend = dend- tmp;
                Cout = Cout + bCout;
            }
        }

        if(flag==true)
            return Cout+addCout;
        else
            return -(Cout+addCout);
    }    
};
```