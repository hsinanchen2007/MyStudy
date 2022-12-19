较简单二分查找题目， 思路：
1、设置 left = 0, right = x；
2、取中间点mid， 若 mid > x/mid （注意mid * mid会溢出），right = mid，否则 left = mid；
3、直到 right - left <= 1时停止，最后输出 left；

Note: 大数相乘会溢出（int）；普通方法查找易超时；

代码如下，欢迎点评：
```
int mySqrt(int x){
    int left = 0;
    int right = x;

    if (x ==0 || x == 1)
        return x;
    while (right - left > 1) {
        int mid = (left + right)/2;
        if (mid > x/mid)
            right = mid;
        else
            left = mid;
    }
    return left;
}
```
