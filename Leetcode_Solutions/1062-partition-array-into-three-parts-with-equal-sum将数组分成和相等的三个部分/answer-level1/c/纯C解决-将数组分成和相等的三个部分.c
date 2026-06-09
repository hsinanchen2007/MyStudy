### 解题思路
这道题还是要看懂题意，人家要我们判断前面连续的和后面连续的子序列是否能够等于总和的三分之一。

并且要保证中间的留有元素给第三个子数组，也就是说三者均不为空。

开始我还是以为和中等难度的将数组分割成和相等的两个部分一样。用01背包捣鼓了半天没有解决。。。

后来发现不是一种题目，这里的已经排序好的了，理解题目就容易做了。并且背包问题是能够有复数的，这样子背包的容量就发生变化了。

### 代码

```c
//双指针
bool canThreePartsEqualSum(int* A, int ASize){
    int low=0,high=ASize-1;
    int sum1=A[low],sum2=A[high],sum=0;

    for(low;low<=high;low++)
    sum+=A[low];

    if(sum%3!=0)//是否是3的倍数
    return false;

    sum/=3;
    low=0;
        while(high-(low+1)>1&&sum1!=sum)
        sum1+=A[++low];
        while((high-1)-low>1&sum2!=sum)
        sum2+=A[--high];
    if(sum1==sum&&sum2==sum)
    return true;
    return false;
}
```