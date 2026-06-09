公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 

## 思路

这道题也是动态规划的思路。

我们先定义状态，使用数组dp保存每步子问题的最优解。
dp[i] 代表从头元素开始，到第i个元素(包含i)的最长上升子序列的长度。

状态转移方程：

```
for i:0 -> n-1:
    dp[i] = Max{dp[j]}+1  j:0->i-1&&a[j]<a[i]
   
```
伪代码：


```
for i: 0->n-1:
  for j: 0->i-1:
        dp[i]
```
这里两层循环，时间复杂度为O(n^2)，空间复杂度O(n)

但是题目中有个进阶，要求我们找出O(nlogn)的时间复杂度的算法。

我们可以想想，在这里的伪代码：

```
for i: 0->n-1:
  for j: 0->i-1: 我们这第二层循环加速
        dp[i]
        
```
为什么我们可以在第二层循环加速，那是因为第一层遍历我们不能省略，只能在第二层想办法。

我们拿题目中的数组来举例子： [10,9,2,5,3,7,101,18]

如果我们维护一个数组L，进来一个新的元素，如果比较最后的元素大，那就加入数组，如果比最后元素小，那就替换。

 
```
 [10]              [10,9,2,5,3,7,101,18]
 [9]               [9,2,5,3,7,101,18]
 [2]               [5,3,7,101,18]
 [2,5]             [3,7,101,18]
 [2,3]             [7,101,18] 3和5比较，使用二分查找插入到5前面并替换5
 [2,3,7]           [101,18]
 [2,3,7,101]       [18]
 [2,3,7,18]        []   长度为4，这里有多种子序列，长度是一样的
 
```
这里使用了二分查找，第二层循环时间复杂度为O(logn)，总体时间复杂度为O(nlogn)。
代码见方案代码。

## 方案代码

动态规划:


```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        dp = [1]
        for i in range(1,len(nums)):
            dp.append(1)
            for j in range(i):
                if(nums[j] < nums[i]):
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)

```
二分查找：

```
import bisect
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []
        for i in range(len(nums)):
            p = bisect.bisect_left(res,nums[i])
            if p == len(res):
                res.append(nums[i])
            else:
                res[p]=nums[i]
                
        return len(res)


```
