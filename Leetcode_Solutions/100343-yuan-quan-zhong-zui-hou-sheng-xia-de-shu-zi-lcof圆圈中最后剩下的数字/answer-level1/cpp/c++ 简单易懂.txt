# 分析
**首先**，我们分析题目中的删除操作。根据题意，在删掉第`m`个元素后，我们是从第`m + 1`个元素处重新开始计数，相当于对整个数组向前平移了`m`个位置，即：`idx = idx - m`，为了实现题目中的圆环效果，即循环链表，我们需要令其对当前数组长度`n`取余，即：`idx = (idx - m) % n`。
**接下来**，又根据题目我们只能知道数组的最终返回的是`n == 1`时,`idx = 0`处的元素，所以我们使用反向递归的思想。上述的删除操作的逆操作显然就是将整个数组向后平移`m`个位置吗，即：`idx = (idx + m) % n`。
# 代码实现
反向递归：
```
int rolling(int n, int m)
{
    if (n == 1)
        return 0;
    return (rolling(n - 1, m) + m) % n;
}
int lastRemaining(int n, int m)
{
    return rolling(n, m);
}
```
调用递归函数会消耗一些额外的资源，所以，将其写成非递归形式：
```
int lastRemaining(int n, int m)
{
    //循环中i表示的便是当前数组长度
    //已知i = 1时ans = 0，根据公式从i = 2计算到n； 
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        ans = (ans + m) % i;
    return ans;
}
```
![1.png](https://pic.leetcode-cn.com/afbb5fa99d87a19a475a96737591f5b0213adee6dd9d65132254a94453731210-1.png)
