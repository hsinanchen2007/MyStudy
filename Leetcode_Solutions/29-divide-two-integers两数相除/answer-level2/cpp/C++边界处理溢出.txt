溢出问题主要发生在-2^31,把这个情况拎出来考虑，减掉/加上一个除数再调用原函数
不使用unsigned int ,其他部分参考评论区foxleezh
```
#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == INT32_MIN){
            if(dividend == INT32_MIN)return 1;
            else return 0;
        }
        if(dividend == INT32_MIN && divisor==-1)return INT32_MAX;
        if(dividend == INT32_MIN){
            if(divisor>0){return divide(dividend+divisor,divisor)-1;}
            else{return divide(dividend-divisor,divisor)+1;}
        }
        int result = 0;
        bool flag = (dividend>0)^(divisor>0);
        int d1 = abs(dividend);
        int d2 = abs(divisor);
        for(int i = 31;i>=0;i--){
            if ((d1>>i)>=d2){
                result += (1<<i);
                d1-=(d2<<i);
            }
        }
        if(flag==false){
            return result;
        }
        else{
            return -result;
        }
    }
};
```
