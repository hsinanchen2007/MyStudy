想到了一种用排列组合来解问题的方法，就是运行时间太长了
主要想法：
 1. 关于0在字符串中的讨论见其他题解。
 2. 首先需要找出列表中所有的连续1，2序列，因为最后的结果只和连续的1，2序列以及这些序列的排列数量有关，例如若序列中全是3到9，则结果必然为1。
 3. 取出的序列`L`无论全是1，全是2，还是1，2混合，并不影响排列的数量，因此该排列`L`数量只和序列长度有关，一个长度为n的序列具有的排列方式为`helper(n)`。
 4. 取出的序列`L`的下一位字符也会影响排列的个数，如果是0的话，相当于取出的序列`L`的最后一位与0必须一起输出，因此序列`L`排序方法有`helper(n-1)`种；如果`L`最后一位是1或者`L`下一位在3-6之间，那么排序方式为`helper(end-cur)+helper(end-cur-1)`，这一点类似动态规划。
 5. 将所有序列的排列方式数量乘起来就可以得到总的排列数量


```python []
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        
        from scipy.special import comb
        def helper(num):
            return sum(comb(num-i,i) for i in range(num//2+1))
        
        s1 = ('1','2')
        s2 = ('3','4','5','6')
        res, n, cur = 1, len(s), 0
        
        while cur < n:
            if s[cur] == '0' and s[cur-1] not in s1:
                return 0
            if s[cur] in s1:
                end = cur
                while end < n:
                    if s[end] in s1:
                        end += 1
                    else:break
                if end < n and s[end] == '0':
                    res *= helper(end-cur-1)
                elif end < n and (s[end-1] == '1' or s[end] in s2):
                    res *= (helper(end-cur)+helper(end-cur-1))
                else:
                    res *= helper(end-cur)
                cur = end
            cur += 1
        return int(res)
```



