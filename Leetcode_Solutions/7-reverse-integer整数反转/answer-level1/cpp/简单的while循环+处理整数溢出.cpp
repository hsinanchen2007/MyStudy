```
package com.com.leetcode;

//整数反转：只需要明白反转的时候res乘num的低位，循环可以实现
//同时注意这么一种情况：由于x的范围为[-2^31,2^31-1]，处理负数的时候要先升为long范围。不然-(-2^31）会造成int溢出。
public class _8reverseNum {
        public int reverse(int x) {
            boolean postive=true;
            long res=0;
            long t=x;//这里将x扩展为long，避免对INT_MIN取反的时候溢出。
            if(t<0){
                t=-t;
                postive=false;
            }
            while(t!=0){
                res*=10;
                res+=t%10;
                t/=10;
            }
            if(postive){
                return res>(long)Integer.MAX_VALUE?0:(int)res;
            }
            return -res<Integer.MIN_VALUE?0:(int)-res;
        }
}

```
