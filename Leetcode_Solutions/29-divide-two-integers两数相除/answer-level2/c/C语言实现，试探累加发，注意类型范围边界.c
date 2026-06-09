执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了74.65%的用户

```
int divide(int dividend, int divisor){
    int flag = 0;
    long long tmpDividend;
    long long tmpDivisor;
    long long realDividend = dividend;
    long long realDivisor = divisor;
    int curb = 1;
    long long ret = 0;
    int divmax = 0xfffffff;
    int maxval = 0x7fffffff;
    long long maxflag = 0x80000000;
    
    if ((realDividend < 0 && realDivisor > 0) || (realDividend > 0 && realDivisor < 0)) {
        flag = 1;
    }
    if (realDividend < 0) {
        realDividend = (long long)((unsigned int)dividend & maxval);
        if (realDividend == 0) {
            realDividend = maxflag;
        } else {
            realDividend = 0 - dividend;
        }
    }
    
    if (realDivisor < 0) {
        realDivisor = (long long)((unsigned int)divisor & maxval);
        if (realDivisor == 0) {
            realDivisor = maxflag;
        } else {
            realDivisor = 0 - divisor;
        }
    }
    
    tmpDividend = realDividend;
    tmpDivisor = realDivisor;
    while (tmpDividend >= realDivisor) {
        if (tmpDividend < tmpDivisor || tmpDivisor > divmax) {
            tmpDivisor = realDivisor;
            curb = 1;
        }
        ret += curb;
        tmpDividend -= tmpDivisor;
        tmpDivisor += tmpDivisor;
        curb += curb;
    }

    if (flag) {
        ret = (int)(0 - ret);
    } else {
        ret = (ret > maxval) ? maxval : ret;
        ret = (int)(ret & maxval);
    }
    return ret;
}
```

