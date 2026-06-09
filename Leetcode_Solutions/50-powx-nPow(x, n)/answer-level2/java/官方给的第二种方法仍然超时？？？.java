本以为官方的第二种方法会很快就得到结果，但是缺仍然超时
参考了一下之前的一题除法的解法：
    
```
public double myPow(double x, int n) {
    if(n==0)return 1;
    double ret=1;
    boolean flag=false;
    if(n==-2147483648){
        n=n+1;
        flag=true;//判断n是不是Integer_MIN
    }
    //翻倍相乘
    int count=1;
    int rest=Math.abs(n);//剩余的幂次
    double temp=x;//乘以的数
    while(rest>0){
        ret=ret*temp;
        rest=rest-count;//剩余次数
        if(count*2<=rest){//小于剩余的幂次，可以倍乘
            temp=temp*temp;//倍乘
            count=count*2;
        }else{
            count=1;//从count=1再开始重新倍乘
            temp=x;//令基数从x开始
        }
    }
    if(flag){
        ret=ret*x;
    }
    if(n>0){
        return ret;
    }else{
        return 1.0/ret;
    } 
      //递归的快速幂仍然会超时
    // if(n==0) return 1.0;
    // if(n==1) return x;
    // long nlong=Math.abs(n);//将其转化为正数，方便计算
    // double ret=myPow2(x,nlong);//调用函数进行递归计算
    // if(n>0){//判断是否要变成倒数
    //     return ret;
    // }else{
    //     return 1.0/ret;
    // }
}
```
其实如果没有限制使用long,可以直接将n转化为long,就不用特别处理n=-2147483648的情况了。
不过感觉这个方法和官方给的也都是一个意思，不知道为啥不会超时，官方的却超时了。
