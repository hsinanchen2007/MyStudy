执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :33.7 MB, 在所有 Java 提交中击败了76.49%的用户

```java []
    /**
     * 不能乘除取余，便只有加法了
     * @param dividend
     * @param divisor
     * @return
     */
    public int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;// 相同数字，返回1
        if(dividend==-divisor) return -1;//相反数，返回-1
        if(divisor==Integer.MIN_VALUE) return 0;//除数为最小数，无解啦，返回0
        boolean positive=((divisor>0&&dividend<0)||(divisor<0&&dividend>0))?false:true;//符号，true：正数；false：负数
        if(divisor==1||divisor==-1){//返回本身或本身的相反数
            if ((dividend>0&&positive) || (dividend< 0&&!positive)) return dividend;
            if(positive&&dividend<0) if (-dividend<0) return dividend-1;//越界
            return -dividend;
        }
        int temp=dividend>0?divisor>0?divisor:-divisor:divisor>0?-divisor:divisor,beginTemp=temp;//与被除数符号一致的临时除数，嘿嘿
        int result=count(dividend,temp);
        return positive?result:-result;
    }

    /**
     * 商倍增，当倍增后的商大于被除数，则不倍增，退出，求出余数，再次递归
     * @param dividend
     * @param temp
     * @return
     */
    private int count(int dividend, int temp) {
        if(dividend>0?temp>dividend:(temp<dividend)){
            return 0;
        }
        int sum=temp;
        int result=1;
        while (dividend>0?sum<=dividend:(sum>=dividend)){
            //溢出 有余 在未翻倍和翻倍中间
            int subSum=sum+sum;
            if((sum>0&&subSum<=0)||(sum<0&&subSum>=0)
                    ||(dividend>0?(sum+temp)>dividend:((sum+temp)<dividend))
                    || (dividend>0?subSum>dividend:(subSum<dividend))) {
                break;
            }
            if(sum+temp==dividend){
                sum+=temp;
                result++;
            }
            sum=subSum;
            result*=2;
        }
        //当余数大于除数，递归余数
        if(dividend>0?dividend-sum>temp:dividend-sum<temp){
            result+=count(dividend-sum,temp);
        }
        return result;
    }
```
