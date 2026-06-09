每次计算当前数字的次数只需要知道他是偶数还是奇数：
1. 如果是偶数，那么他的次数就是：1 + dp(n / 2);
2. 如果是奇数，那就是加一还是减一的次数少的那种：1 + MIN(dp(n + 1), dp(n - 1)); 
3. 此时需要注意一点，由于我们才计算到n， 所以无法得到n+1的结果，需要进行一次转换
4. 不管是n+1还是n-1一定是偶数了，所以按照偶数的规律，dp(n + 1) = 1 + dp((n + 1) / 2), dp(n - 1) = 1 + dp((n - 1) / 2)

最后，由于我们只需要输出最后一次的结果，不需要保留中间值，所以，我们需要使用递归方式实现这个动态规划：
注意由于中间有加一操作，所以长度需要用long型数据：

#define MIN(a, b)   ((a) > (b) ? (b) : (a))
long dp(long val)
{
    if (val == 0 || val == 1) {
        return 0;
    }

    if (val % 2 == 0) {
        return 1 + dp(val / 2);
    } else {
        return 1 + MIN(1 + dp((val + 1) / 2), 1 + dp((val - 1) / 2));
    }
}

int integerReplacement(int n){
    if (n < 0) {
        return -1;
    }

    return dp(n);
}