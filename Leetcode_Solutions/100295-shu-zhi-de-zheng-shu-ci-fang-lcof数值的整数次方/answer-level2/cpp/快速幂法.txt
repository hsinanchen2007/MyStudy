class Solution {
public:
    double myPow(double x, int n) {
        //当n是负数的时候， while(n)也是真
        //n是偶数的话，直接将n对半拆开，x变为x*x;
        //n是奇数的话， 将(x, n) 分为x 和x(x, n-1), 其中x在循环过程中类积(乘)到result中
        //开始时候不考虑n的正负性，最后考虑当n为负数时候，返回最终结果的倒数
        //n为正数，使用移位n>>=1; ,n最终结果是0，会使得循环停止
        //n为负数的时候， 使用移位，n的最终结果是-1（1111 1111），循环不会终止，
        //并且-3/2== -1； -3>>1== -2; 结果不一样，对于负数不能移位
        double result = 1.0;
        int t = n;
        while(n){
            if(n&1)
                result = result * x;
            x = x * x;
            n/=2;
        }
        return t>0?result:1.0/result;
    }
};