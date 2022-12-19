解答转自：https://blog.csdn.net/ju136/article/details/8153274

# 问题1

给定一个数组，长度为n，除a[0]以外，其他元素都是a[i] == i。那么请找出第一个大于0，且不在此数组中的最小整数。

答案就是:  n + (a[0] == n);

# 问题2

给定一个数组，长度为n，某几个位置的元素满足 a[x] < 0 或者 a[x] > n，余下的元素都满足a[i] == i。那么请找出第一个大于0，且不在此数组中的最小整数。

答：

很明显：当x的值限定为0时。就变成了问题1。
除此之外，这个问题的解也容易求得。

情况1： 首先从1~n开始扫描，当发现i != a[i]时，直接返回i。此时的i必定是最小的未出现的整数。
情况2： 当扫描完1~n之后，那么就回归至问题1了。

```cpp
for (i = 1; i < n; ++i) {
    if (i != a[i]) return i;
}
return (n + (n == a[0]));
```

# 问题3

当给出问题2之后，就需要考虑如何把原题目转换成为问题2了。

实际上要完成的任务就变成了，如何把一个数组中的元素元神归位。也就是让a[i] == i。如果能让这些元素元神归位，那么就转换成为问题2了。就很容易求解了。

算法如下：

       我们从后往前扫描，i = n - 1 to 0;
                  step1如果发现a[i] < 0 || a[i] > n; 则 continue;
                  step2 如果发现a[i] == a[a[i]]; 则continue;
                  step3 如果发现0 < a[i] < n
                          说明需要将a[i]元神归位。也就是放到a[a[i]]上去。
                           swap(a[i], a[a[i]]).
                           再跳转至step2。

Note: 需要注意一种有重复数的情况，比如a[11] = 2, a[2] = 2。这时候，就不用进行交换了。直接处理下一个元素。

可以给出代码：
```cpp
int i = n, t, temp;
if (!a || n <= 0) return -1;

while ((--i) >= 0) {
    while (0 < a[i] && a[i] < n && i != a[i]) {
        t = a[i];
        if (a[i] == a[t]) break;
        temp = a[i];
        a[i] = a[t];
        a[t] = temp;
    }
}
```

好吧，到现在为止，原题已经变得很简单了。可以直接给出代码了。

# 原题解答

```cpp
int find(int *a, int n) {
    int i = n, t, temp;
    if (!a || n <= 0) return -1;

    while ((--i) >= 0) {
        while (0 < a[i] && a[i] < n && i != a[i]) {
            t = a[i];
            if (a[i] == a[t]) break;
            temp = a[i];
            a[i] = a[t];
            a[t] = temp;
        }
    }

    for (i = 1; i < n; ++i)
        if (a[i] != i) return i;

    return (n + (a[0] == n));
}
```

# 算法复杂度分析

去原地址查看： https://blog.csdn.net/ju136/article/details/8153274

