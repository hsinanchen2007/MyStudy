```
    /**
     * 位运算 dividend 不停的去减 divisor*2^x (x = 31-0)逼近
     * 题目上要求只能用32位存储，所以网上说的用long升位代替32位无符号数有点不严谨
     * 所以需要额外的处理和判断
     * @param dividend
     * @param divisor
     * @return
     */
    public int divide(int dividend, int divisor) {
        if(divisor == 0){
            //除数不能为0
            return 0;
        }
        //针对溢出和不用long类型做特殊处理
        if(dividend == Integer.MIN_VALUE) {
            if (divisor == -1) {
                //这种情况会溢出
                return Integer.MAX_VALUE;
            } else if (divisor == Integer.MIN_VALUE) {
                return 1;
            }
        }
        //其他情况除数为0x80000000的情况直接返回0
        if(divisor == Integer.MIN_VALUE){
            return 0;
        }else if(divisor == 1){
            return dividend;
        }

        //然后结果的正负号
        boolean sign = false;
        if((dividend ^ divisor) < 0){
            sign = true;
        }

        //然后新除数和被除数
        int unsignedDivisor = Math.abs(divisor);
        int unsignedDividend = 0;
        int unsignedMore = 0;
        if(dividend == Integer.MIN_VALUE){
            unsignedDividend = Integer.MAX_VALUE;
            unsignedMore = 1;
        }else {
            unsignedDividend = Math.abs(dividend);
        }
        int result = 0;
        int i = 31;
        while (i >= 0){
            if((unsignedDividend >> i) >= unsignedDivisor){
                result += 1 << i;
                unsignedDividend = unsignedDividend - (unsignedDivisor << i) + unsignedMore;
                if(unsignedMore > 0){
                    unsignedMore = 0;
                }
            }else {
                i--;
            }
        }
        return sign ? -result : result;
    }
```