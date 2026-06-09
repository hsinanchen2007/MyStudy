 public static int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 0 || Math.abs((long)dividend) < Math.abs((long)divisor)){
            return 0;
        }
        
        long absDividend = Math.abs((long)dividend);
        long absDivisor = Math.abs((long)divisor);
        long san = calculate(absDividend, absDivisor);

        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            san = -san;
        }

        if(san < Integer.MIN_VALUE || san > Integer.MAX_VALUE){
            san = Integer.MAX_VALUE;
        }

        return (int)san;
    }

    private static long calculate(long absDividend, long absDivisor){
        long num = 0;
        long temp = absDivisor;
        while(temp <= absDividend){
            num ++;
            temp <<= 1;
        }
        num = 1L << (num-1);
        temp >>= 1;
        if(absDividend - temp >= absDivisor){
            num += calculate(absDividend - temp, absDivisor);
        }
        return num;
    }