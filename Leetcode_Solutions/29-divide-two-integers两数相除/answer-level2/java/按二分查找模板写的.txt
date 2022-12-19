除了异或判断符号位，其他没有用到位运算，都是加减运算，性能还是够用的。

题目分类提示了二分查找，那么按二分查找的思路去想就行了，既然要求不能使用乘除模运算，那么就让除数不断自加倍增，与被除数对比，倍增过头了就初始化为原始的除数值再次循环倍增，循环过程中被除数减去除数不断减小，直到小于除数为止，其过程就是把二分查找中的 mid=(left+right)/2 替换成了divisor*2，把 left 和 right 替换成了 divisor_tmp 和 divideng_tmp，这样理解就比较直观了。

位运算我现在没什么思路，目前唯一想到的就是除数和被除数都 x&(-x) 取最低位的1，Math.min取小值，然后移位清掉后面的0，然后再进入二分循环，不知道这样会不会快一些。第一次写解答，自己好菜啊，只自学了一个多月的java，菜鸡瑟瑟发抖，欢迎大佬指点批评。╭(￣▽￣)╯

```
class Solution {
    public int divide(int dividend, int divisor) {
        /** 除数为零就返回-1 按照测试样例的要求写的*/
        if (divisor==0)
            return -1;
        if (dividend==0)
            return 0;
        /** -2147483648, -1 这个测试样例的确没想到，结果翻车了*/
        if (dividend==Integer.MIN_VALUE && divisor==-1)
            return Integer.MAX_VALUE;
        /** 符号位的处理参考了大佬的异或处理方法*/
        boolean negetive= (dividend^ divisor)<0;
        /** div_count 是当前divisor_tmp相对于divisor的倍数 */
        int res=0, div_count=1;
        /** 因为值溢出之后边界问题处理太繁琐了，直接将数值转为long省去麻烦 */
        long dividend_tmp= Math.abs((long)dividend);
        long divisor_tmp= Math.abs((long)divisor);
        
        /** 按标准的二分查找代码模板写的 */
        while (dividend_tmp>= divisor_tmp) {
            dividend_tmp-= divisor_tmp;
            res+= div_count;
            
            if (dividend_tmp< Math.abs(divisor))
                break;
            
            /** divisor_tmp无法倍增时，就将其初始化为divisor绝对值，重新开始下一轮倍增*/
            if (dividend_tmp- divisor_tmp< divisor_tmp) {
                divisor_tmp= Math.abs(divisor);
                div_count=1;
                continue;
            } 
            
            /** 不断倍增divisor_tmp直到和dividend_tmp一样大*/
            divisor_tmp+= divisor_tmp;
            div_count+= div_count;
        }
        return negetive? 0-res: res;
    }
}
```