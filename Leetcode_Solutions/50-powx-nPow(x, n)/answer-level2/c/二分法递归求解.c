这个问题考察的是"快速幂"的问题，在求一个数的次幂时，如果幂次非常大，机械性的一遍一遍乘，效率太低。我们可以将
$x^n$分解为$x^{\frac{n}{2}}$$\times$$x^{\frac{n}{2}}$或$x^{\frac{n-1}{2}}$$\times$$x^{\frac{n-1}{2}}$$\times x$，
之后每一个问题再次按照该原则分解，直至$n=0,1$
将上面的思路具体细化一下，就得到下面的具体步骤
算法步骤：
    1. 如果x=1，0，或n=1，直接返回x。
    2. 如果n=0，返回1。
    3. 如果n<0，将n取反为整数，返回myPow(x,-n)的倒数，但由于最小负数取反后会溢出，所以将myPow(x,-n)拆分为myPow(x,-n)*x。
    4. 如果n>0，n为偶数时，返回myPow(x,n/2)的平方，n为奇数时，返回myPow(x,n/2)的平方*x。
    
```
double myPow(double x, int n){
        if(x==0||x==1||n==1)
        return x;

        if(n==0)
            return 1;
        if(n<0)
            return 1/(myPow(x,-(n+1))*x);
        else
            {
                double s=myPow(x,n/2);
                if(n%2==0)   
                    return s*s;
                else
                    return s*s*x;
            }
 }
```