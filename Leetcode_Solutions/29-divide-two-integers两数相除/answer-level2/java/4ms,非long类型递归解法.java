java基于递归实现思路(非long类型) 基于位运算，指数增长除数，加快运算
4ms
```
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if(dividend == 0 || divisor == 0) return 0;
        int less = 0;//判断大于0的个数，用于判断商的符号
        int t = divisor;
        //int的范围为-2^32 ～ 2^32-1，负数的范围较大，因此全部转为负数来计算
        if(dividend > 0){
            less++;
            dividend = -dividend;
        }
        if(divisor > 0){
            less++;
            divisor = -divisor;
        }
        //如果被除数大于除数，则直接返回0
        if(dividend > divisor) return 0;
        //递归获取商
        int getcount = getcount(dividend, divisor);
        //如果符号不同则返回负数
        return  less == 1 ? -getcount:getcount;
    }

    int getcount(int count,int one){
            int d =one,sum = 1;
            //结束条件，判断当前的商小于或者等于1的情况
            if(count - d > d){
                //如果是3除以4 则返回0
                if(count - d > 0) return 0;
                //如果是5除以4 则返回1
                return 1;
            }
            //递归获取值
            for(int i = 0 ; i < 32 ; i++){
                //指数增大除数
                d = d << 1;
                //相减
                int temp = count - d;
                sum = sum << 1;
                //除数指数增大，相减直到大于除数
                if(count - d > d){
                    //继续递归相减后的值，当我们的temp/one的值小于等于1时递归结束
                    sum += getcount(temp,one);
                    break;
                }
            }
            return sum;
    }
```
