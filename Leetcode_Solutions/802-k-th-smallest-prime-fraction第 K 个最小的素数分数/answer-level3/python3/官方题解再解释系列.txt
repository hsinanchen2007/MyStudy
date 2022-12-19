```
代码块'''
LeetCode 786 第 K 个最小的素数分数
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.
What is the K-th smallest fraction considered? 
Return your answer as an array of ints, where answer[0] = p and answer[1] = q.
Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.
Input: A = [1, 7], K = 1
Output: [1, 7]
Note:
A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.

题目大意：
一个已排序好的表 A，其包含 1 和其他一些素数.  当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。
那么第 k 个最小的分数是多少呢?  以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.
示例:
输入: A = [1, 2, 3, 5], K = 3
输出: [2, 5]
解释:
已构造好的分数,排序后如下所示:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
很明显第三个最小的分数是 2/5.
输入: A = [1, 7], K = 1
输出: [1, 7]
注意:
A 的取值范围在 2 — 2000.
每个 A[i] 的值在 1 —30000.
K 取值范围为 1 —A.length * (A.length - 1) / 2

PS：https://www.jianshu.com/p/801318c77ab5 你看下

解题思路：
方法1：二分法
方法一：二分查找【通过】
under(x) 用于求解小于 x 的分数数量，这是一个关于 x 的单调增函数，因此可以使用二分查找求解，单调性是二分法重要标志。
使用二分查找找出一个 x，使得小于 x 的分数恰好有 K 个，并且记录其中最大的一个分数。
这个二分搜索与其他的二分搜索方法类似：初始有区间 [lo, hi]，中心点 mi = (lo + hi) / 2.0。
如果小于 mi 的分数数量小于 K，更新区间为 [mi, hi]，否则更新为 [lo, mi]。
under(x) 函数有两个目的：返回小于 x 的分数数量以及小于 x 的最大分数。
在 under(x) 函数中使用滑动窗口的方法：对于每个 primes[j]，找出最大的 i 使得 primes[i] / primes[j] < x。
随着 j （和 primes[j]）的增加， i 也会随之增加。
代码如下：
class Solution(object):
    def kthSmallestPrimeFraction(self, primes, K):
        from fractions import Fraction
        def under(x):
            # Return the number of fractions below x,
            # and the largest such fraction
            count = best = 0
            i = -1
            for j in range(1, len(primes)):
                while primes[i+1] < primes[j] * x: # 该分数小于x，i+1并且记录count+1
                    i += 1
                count += i+1
                if i >= 0:
                    best = max(best, Fraction(primes[i], primes[j])) # 更新记录最大值
            return count, best

        # Binary search for x such that there are K fractions
        # below x.
        lo, hi = 0.0, 1.0 # 因为输入只有一个1，分数区间就是0～1
        while hi - lo > 1e-9:
            mi = (lo + hi) / 2.0
            # 这个under在上面是计算输入的，也就是说在输入数组进行查询，小于mi的分数的数量，因为under单调，所以用二分必定可以找出唯一解答
            count, best = under(mi)
            if count < K:
                lo = mi
            else:
                ans = best
                hi = mi
        return ans.numerator, ans.denominator
方法2：堆 也就是优先级队列，也叫最小堆，我这个代码可以过
使用一个堆记录所有以 primes[j] 为分母且未被弹出的最小分数。依次从堆中弹出 K-1 个元素，此时堆顶的分数就是结果。
在 Python 中，使用 (fraction, i, j) 表示分数 fraction = primes[i] / primes[j]。
如果下一个分数有效（即 i+1 < j），那么使用当前分数时，将下一个分数压入堆中。
import heapq
class Solution(object):
    def kthSmallestPrimeFraction(self, A, K):
        pq = [(A[0] / float(A[i]), 0, i) for i in range(len(A) - 1, 0, -1)] # 初始化堆为（小数值，下标0，下标i）

        for _ in range(K-1): # 弹出k-1个最小值，剩下就是第k小的了
            frac, i, j = heapq.heappop(pq) # 弹出第一小
            i += 1 # 分子在A中的位置后移，因为不仅仅只有0/i，比如A = [1, 2, 3, 5]，不仅仅有1/5，也有2/5
            if i < j: # 新位置也可以与j构成小数，就加进去堆
                heapq.heappush(pq, (A[i] / float(A[j]), i, j)) # 加进去堆
                # ps：为什么该方法可行？因为初始化的堆都是0/i，一定小于1/i，因为A是给定单调的
                # 那为什么有一个i后移，加入堆堆操作？因为0/j最小了，但是对于3/j，可能存在2/j-1更小
                # 实质就是全部分数都判断了，但是省去了太大和太小的

        return A[pq[0][1]], A[pq[0][2]]
'''
class Solution(object):
    def kthSmallestPrimeFraction(self, primes, K):
        from fractions import Fraction
        def under(x):
            # Return the number of fractions below x,
            # and the largest such fraction
            count = best = 0
            i = -1
            for j in range(1, len(primes)):
                while primes[i+1] < primes[j] * x: # 该分数小于x，i+1并且记录count+1
                    i += 1
                count += i+1
                if i >= 0:
                    best = max(best, Fraction(primes[i], primes[j])) # 更新记录最大值
            return count, best

        # Binary search for x such that there are K fractions
        # below x.
        lo, hi = 0.0, 1.0 # 因为输入只有一个1，分数区间就是0～1
        while hi - lo > 1e-9:
            mi = (lo + hi) / 2.0
            # 这个under在上面是计算输入的，也就是说在输入数组进行查询，小于mi的分数的数量，因为under单调，所以用二分必定可以找出唯一解答
            count, best = under(mi)
            if count < K:
                lo = mi
            else:
                ans = best
                hi = mi
        return ans.numerator, ans.denominator

if __name__ == "__main__":
    A = [1, 2, 3, 5]
    K = 3
    s = Solution()
    p, q = s.kthSmallestPrimeFraction(A, K)
    print(p, q)
```
