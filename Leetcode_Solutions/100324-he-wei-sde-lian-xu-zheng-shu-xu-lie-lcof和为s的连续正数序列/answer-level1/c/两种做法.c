### 解法一：滑动窗口
71.43% 100%

题目说**连续的**正整数序列`->`滑动窗口法

`l`表示窗口左边界，`r`表示右边界。窗口滑动的条件（循环条件）是① l <= r ② r <= 最大可能出现的数字
根据数学分析（可以举几个例子），最大可能出现的数字为target/2+1.

在窗口滑动遍历内部（循环内部），若sum值小于target则右边界+1；若sum值大于target则左边界+1；若sum == target则找到一个答案，此时`r++`，`sum+=r`得以在满足循环条件下继续滑动窗口。

用c语言此题最麻烦的是返回二维数组。我的做法是将每次找到的答案的`l`和窗口的长度记录在开辟好的两个数组；ls[]和lens[]中（由target<100000 `->` 获得的解的个数<400），再用变量i记录解的个数。
窗口滑动遍历结束后，用malloc先开辟长度为i的指针数组a，再让指针数组中的每个指针指向一个数组，这个数组长为lens[j]。


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int l,r,i,j,k;
    int sum = 0;
    int ls[400] = {0};
    int lens[400] = {0};
    for(l = 1, r = 1, i = 0; r <= target/2+2 && l <= r;)//此处+2是因为下面是先sum+r再r++,也就是r指向的是窗口的右边界的下一个数
    {
        if(sum < target)
        {
            sum += r;
            r++;
        }
        else if(sum > target)
        {
            sum -= l;
            l++;
        }
        else
        {
            ls[i] = l;
            i++;
            sum += r;
            r++;
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int)*i);
    int **a = (int **)malloc(i*sizeof(int *));
    for(j = 0; j < i; j++)
    {
        a[j] = (int *)malloc(lens[j]*sizeof(int));
        a[j][0] = ls[j];
        for(k = 1; k < lens[j]; k++)
        {
            a[j][k] = ++(ls[j]);
        }
        (*returnColumnSizes)[j] = k;
    }
    *returnSize = i;
    return a;
}
```

### 解法二：数学(((

100% 100%

在评论区看到大神解法特地实践，大神果不欺我（话说都没看到几个c解法，c真的没落了吗or2）

首先我们需要知道：
1. 若连续序列和是一个整数，这样同样长度的序列只有一个（也可能没有）。即若target=9，能满足这个的长度为2的序列只有[4、5]，长度为3的序列只有[2、3、4]，以此类推。
2. 当序列的长度越短，里面的数值越大，即按照从小到大的顺序排列解的序列的话，长度短的序列在后面。


接下来，我们可以知道：
1. 当和为target的序列有长度为2，将较大的数-1得到两个相等的数，此时若target-1 == 是2的倍数，将其/2则得到所需序列前一个数，即找到序列。
2. 当和为target的序列有长度为3，将最大的数-2，再将较大的数-1，得到三个相等的数，此时若target-2-1是3的倍数，将其/3则得到所需序列的最前面的数，即找到序列。
3. 以此类推……

不多说，贴代码，记得最后记录的顺序是从短到长的序列，将其反过来保存就得到第一个值从小到大的序列了。

### 代码

```c
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int n = 2;
    int i = 0, j, k;
    int ls[400] = {0},lens[400] = {0};
    target -= 1;
    while(target > 0)
    {
        if(target % n == 0)
        {
            ls[i] = target/n;
            lens[i] = n;
            i++;
        }
        target -= n;
        n++;
    }
    int **a = (int **)malloc(sizeof(int *)*i);
    *returnSize = i;
    *returnColumnSizes = (int *)malloc(sizeof(int)*i);
    for(j = i - 1; j >= 0; j--)
    {
        a[j] = (int *)malloc(sizeof(int)*lens[i - j - 1]);
        a[j][0] = ls[i - j - 1];
        for(k = 1; k < lens[i - j - 1]; k++)
        {
            a[j][k] = ++(ls[i - j - 1]);
        }
        (*returnColumnSizes)[j] = k;
    }
    return a;
```
