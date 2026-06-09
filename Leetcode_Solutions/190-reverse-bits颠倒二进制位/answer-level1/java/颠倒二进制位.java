1. 首先声明这是根据陈乐乐同学的C++代码改变而来的Java代码，侵删。
[@chenlele](/u/chenlele/)
```
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int i=32;
        int rev=0;
        boolean t=true;
        while(t)
        {
            rev<<=1;//向左移一位
            rev+=n&1;//取原数据最后一位
            n>>=1;//向右移一位
            i-=1;
            if(i==0){
                t=false;
            }
            
        }
        return rev;



    }
}
```
思路是采用位运算，每次取原数据最后一位push进新的数据中，循环32次，即可实现颠倒二进位。
