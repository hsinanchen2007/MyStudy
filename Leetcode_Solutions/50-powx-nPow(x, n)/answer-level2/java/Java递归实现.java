负数的范围比正数大，所以先把n转为负数再计算，避免越界

class Solution {
    public double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n>0)
            return 1/myPow(x,-n);   //n>0,转为负数计算
        if(n%2==0)                  
            return myPow(x*x,n/2);  //n为偶数，x平方，n折半
        return 1/x*myPow(x*x,n/2);  //n为奇数，x平方，n折半，多乘一个1/x 
    }  
}
