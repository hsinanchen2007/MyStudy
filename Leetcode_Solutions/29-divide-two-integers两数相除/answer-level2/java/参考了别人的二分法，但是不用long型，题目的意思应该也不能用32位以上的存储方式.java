```
class Solution {
    public int divide(int dividend, int divisor) {
       if(dividend==0 || divisor==0) return 0;
       //除数是-2147483648
       if(dividend==-2147483648 && divisor==-1) return Integer.MAX_VALUE;
       //被除数是-2147483648的问题
       if(dividend==-2147483648 && divisor==-2147483648) return 1;
       if(divisor==-2147483648)return 0;

       boolean flag=false;//判断是不是-2147483648
       if(dividend==-2147483648){
           dividend=dividend+1;//+1保证不溢出
           flag=true;
       }
       boolean negtive=(dividend ^divisor)<0;//异或，如果两个符号不同，异或之后最高位符号必定为1，即为负数
       int dividend1=dividend>0?dividend:0-dividend;//将数字都变成正数，便于处理
       int divisor1=divisor>0?divisor:0-divisor;
       int res=0,count=1;//存储结果，以及除的次数
       while(dividend1 >= divisor1){
           dividend1=dividend1-divisor1;
           res=res+count;
           if(dividend1<Math.abs(divisor)) {
               if(!flag){
                   return negtive? 0-res: res;
               }else{//做了+1处理，判断最后的余数还能不能整除
                    if(dividend1+1==Math.abs(divisor)){
                        return negtive? 0-res-1: res+1; 
                    }else{
                        return negtive? 0-res: res;
                    }
               }
           }
           if(dividend1-divisor1<divisor1){//无法倍增
                divisor1=Math.abs(divisor);
                count=1;
                continue;
           }
           //倍增
           divisor1+=divisor1;
           count+=count;
       }
       return 0;
    }
}
```
