这题只有一种特殊情况，
-2147483648 和 -1的情况，因为都是整数，所以只有这种情况下，会出现2147483648这个不存在的数值。
其他情况都不会溢出！！！
防止溢出1：
把dividend都变成divisor负数，并且记录结果最后的正负， 就不会出现-2147483648变成正数的溢出。

然后说翻倍法，递归实现。
三个数，dividend，divisor和count，14和3为例子
14 > 3,count=1
14 > 6,count=2
14 > 12.count=4
14 <  24,count=count+method(14-12,3) 递归执行

脱离递归的条件是，dividend<divisor或者dividend<2divisor，return0和1，因为剩下的dividend不能翻倍了就没必要递归下去了
divisor和count循环一次翻倍一次，count表示目前可以减去多少个divisor

防止溢出2：
divisor不断翻倍的过程中 可能溢出，变成一个正数，导致不断的循环下去，永不结束，
if (divisor+divisor>divisor)判断溢出，因为是负数，所以会越来越小，溢出就会变大。











public static int divide(int dividend, int divisor)
    {
        boolean nagtiveFlag;
        if (dividend<0 && divisor>0 || dividend>0 && divisor<0)
            nagtiveFlag=true;
        else
            nagtiveFlag=false;

        if(dividend>0)
            dividend=-dividend;
        if(divisor>0)
            divisor=-divisor;
        int result = helper(dividend,divisor);
        if(result==Integer.MIN_VALUE && nagtiveFlag==false)
            return Integer.MAX_VALUE;

        if (nagtiveFlag==true)
            return result;
        else
            return -result;
    }

    public static int helper(int dividend, int divisor)
    {
        int count=0;
        int d=divisor;
        if (dividend>divisor)
            return 0;
        if (dividend>divisor+divisor)
            return -1;
        int predivisor=divisor;
        while (dividend<=divisor)
        {
            predivisor=divisor;

            if (count==0)
                count=-1;
            else
                count+=count;
            
            if (divisor+divisor>divisor)
                return count+helper(dividend-predivisor,d);
            divisor+=divisor;
        }
        return count+helper(dividend-predivisor,d);
    }