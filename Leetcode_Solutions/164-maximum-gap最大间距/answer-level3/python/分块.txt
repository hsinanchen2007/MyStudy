自己没想出来，看了题解（说实话，看文字远没有代码直观，原理其实也不难）
说这题用到鸽巢原理总觉得怪怪的，虽然也并没有什么问题

言归正传，题目想求的是数之间的最大间隔

最大间隔=>最大=>二分答案

但是这题似乎并不是很好二分，因为要检查一个数周围+/-ans的范围内是否有数并不是一件容易的事情
那么再来分析一下答案的界

上界：最极端就是两端
下界：？
这时候发现，下界不是0，似乎是(Max-Min) // (n-1) + 1
那这个下界怎么用呢？

如果将整个区间按这个下界分块，那么总共就有n块（就是题解中的桶）
而每个数肯定落在其中一个块中（废话）

而且，**答案对应的两个数一定在块间，而不是块内**，因为块内的间距小于等于下界
而块间的最大间距就很好求了，维护每个块内的最大最小值即可

所以，如果从**分块**的角度来思考这道题才对

常规的分块是按sqrt(n)分，块间最大间距复杂度O(sqrt(n))，块内最大间距复杂度最大可以到O(n^2)，显然不平衡，那增大块间最大间距，发现，当块间最大间距复杂度变为O(n)时，**块内可以不用计算了，因为答案肯定不在块内**，从而复杂度就成了O(n)

``` python
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 2:
            return 0
        L = min(nums)
        R = max(nums)

        interval = (R-L) // n + 1

        Max = dict()
        Min = dict()

        for v in nums:
            idx = (v-L) // interval
            if idx in Max:
                Max[idx] = max(v, Max[idx])
                Min[idx] = min(v, Min[idx])
            else:
                Max[idx] = v
                Min[idx] = v
        
        preMax = L
        Ans = 0

        for i in range(n+1):
            if i in Max:
                Ans = max(Ans, Min[i]-preMax)
                preMax = Max[i]
        
        return Ans
```