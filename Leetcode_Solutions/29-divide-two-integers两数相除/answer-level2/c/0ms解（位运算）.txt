```
int divide(int dividend, int divisor){
    //都转换成正数用long long存储，用整型t表示结果正负
    long long a=dividend,b=divisor;
    if(a==0)
        return 0;
    int t=1;
    if(a<0){
        t=-t;
        a=-a;
    } 
    if(b<0){
        t=-t;
        b=-b;
    }
    //数组e每个元素表示被除数二进制位数依次递增的对应结果，sum用于存储运算结果
    long long sum=0;
    long long e[32]={0};
    for(int i=0;i<32;i++)
        e[i]=a>>i;
    for(int i=31;i>=0;i--){
        sum<<=1;
        if(e[i]>=b){
            sum++;
            //每当满足条件时，数组e中当前位置之前的元素减去对应的数值
            for(int j=i-1;j>=0;j--)
                e[j]-=b<<(i-j);
        }
    }
    //根据对应条件返回结果
    if(t<0)
        return -sum;
    if(sum==2147483648)
        return 2147483647;
    return sum;
    //属实学渣题解
}
```
