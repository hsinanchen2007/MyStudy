class Solution {
public:
    int hammingDistance(int x, int y) {
        /*
        法一:
        int res=0;
        while(y||x)
        {
            int a=x & 0x01,b=y & 0x01;//截取二进制位的最后一位
            if(a^b)
                res++; 
            x>>=1;
            y>>=1;
        }
        return res;
        */

        /*
        法二：奇数%2==1，偶数%2==0
        int res=0;
        while(x||y)
        {
            if(x%2!=y%2)
                res++;
            x=x/2;
            y=y/2;
        }
        return res;
        */

        //法三:N&（N-1）计算二进制位中1的个数
        int res=0,val=x^y;
        while(val!=0)
        {
            res++;
            val&=val-1;
        }
        return res;
    }
};