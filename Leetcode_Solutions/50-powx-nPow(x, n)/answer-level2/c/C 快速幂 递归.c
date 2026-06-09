### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f0b34cd7a3d82b446df43f7abca19ed0b5d8ce4928d64b2678c8e00e6e22184e-image.png)
**复杂度分析**
**时间复杂度：O(logn)**. 每一次我们使用公式(x^n)^2=x^(2*n), n都变为原来的一半。因此我们需要至多 O(logn) 次操作来得到结果。
**空间复杂度：O(logn)**. 每一次计算，我们需要存储x^(n/2)的结果。 我们需要计算 O(logn) 次，所以空间复杂度为 O(logn) 。

### 代码

```c
        //对x 和 n 的值进行特殊处理
        //最小值：Integer.MIN_VALUE= -2147483648 （-2的31次方）
        //最大值：Integer.MAX_VALUE= 2147483647  （2的31次方-1）
        //这里需要使用long类型，因为如果传入的n = -2147483648； 那么转成正数就丢失，所以要使用long
double fastPow(double x, long n){
    if(0 == n)
        return 1.0;
    double half = fastPow(x, n/2);
    if(n%2 == 0){
        return half * half;
    }else{
        return half * half * x;
    }
}
double myPow(double x, int n){
    if(x == 1.0) return 1.0;
    if(x == -1){
        if(n%2 == 0) return 1.0;
        else return -1.0;
    }
    long long N = n;
    if(N < 0){
        x = 1/x;
        N = -N;
    }
    return fastPow(x, N);
}
```