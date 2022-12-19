```
class Solution {
    public int divide(int dividend, int divisor) {
        int negtive=0;
        int flag=0;//是否是-2147483648
        if((dividend^divisor) <0) negtive=-1;//最高位有一个负数，表明结果应该是负数，异或能判断出来
        //溢出情况：-2147483648/-1,除数是0,负数转为正数：-2147483648会溢出，考虑将其+1，最后再加回来
        //不能一点点相减，效率太低，考虑倍减：如2147483647/2》》除以2,4,8,16……不能倍增就从2再开始
        //几种特殊情况可以并在后面，也可以直接写在这里，遇到这几种直接返回结果就行
        if(dividend==-2147483648 && divisor==1)return -2147483648;
        if(dividend==-2147483648 && divisor==-1) return 2147483647;
        if(dividend==-2147483648){
            dividend=2147483647;
            flag=1;
        }
        if(dividend<0)dividend=-dividend;
        if(divisor<0)divisor=-divisor;//将除数被除数都化为正数
        int ret=0;//最终结果
        int count=1;//现在是除以几倍
        int tempdivisor=divisor;//当前除数
        while(dividend-divisor>=0){
            ret+=count;
            dividend=dividend-tempdivisor;
            if(dividend>tempdivisor+tempdivisor){
                //要是除数的两倍才能倍增，如137/48可以倍增，137/96就不能倍增啦
                count +=count;//倍数翻倍
                tempdivisor+=tempdivisor;//除数翻倍
            }else{
                count=1;
                tempdivisor=divisor;
            }
        }
        if(flag==1){//消除被除数+1的影响，如最后剩3/4，就需要把结果+1
            ret=ret+((dividend+1==divisor)?1:0);
        }
        return negtive==0?ret:-ret;//正负判断
    }
}
```
