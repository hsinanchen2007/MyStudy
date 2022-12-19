```cpp
/*
根据当前数n二进制的最后两位，判断下一步该怎么操作：
*00:n>>=1;
*10:n>>=1;
*01:n-=1;
*11:n+=1;

需要注意的事项
(1)溢出：INT_MAX将首先执行+1操作，会溢出的；
(2)特殊情况：3->2->1比3->4->2->1快，很神奇的情况；

时间复杂度：O(1)
最多只需要执行32次操作；
*/
class Solution {
public:
    int integerReplacement(int n) {
        if(n<=0)return -1;
        if(n==3)return 2;
        int res=0;
        unsigned long long ln=n;
        while(ln>1){
            int last2bit = ln&0b11;
            if(last2bit==0b00 || last2bit==0b10)ln>>=1;
            else if(last2bit==0b01 || ln==3)ln-=1;
            else ln+=1;
            ++res;
        }
        return res;
    }
};
```
