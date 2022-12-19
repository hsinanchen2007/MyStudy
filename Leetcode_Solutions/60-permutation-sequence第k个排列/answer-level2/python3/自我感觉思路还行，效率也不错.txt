执行用时 : 32 ms, 在Permutation Sequence的Python提交中击败了98.08% 的用户

内存消耗 : 11.8 MB, 在Permutation Sequence的Python提交中击败了31.71% 的用户

创建一个列表[1,2,...n]，每次计算该放哪个位置的数，比如n = 3，k = 5
首先第一位应该放3，即列表第二位的数，第二位是怎么求的，tmp = (k-1) // (n-1)! = 2
此时，k -= tmp * (n-1)!,n -= 1
然后删除列表中的3，在判断第二位该放哪个位置的数，和上面计算方法一样。

更直观一点的理解，我们让输出的第几个从0开始而不是从1开始，即题目要求输出第k个实际上用k-1来算
k-1 = a(1)*(n-1)! + a(2)*(n-2)! + ... + a(n-2)*2! + a(n-1) * 1
a(1)是第一个数字在列表中的位置，删除l列表中的a(1)位置，第二个数字为列表的a(2)位置，删除列表的a(2)位置。。。
以此类推
```python []
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if k == 0:
            return ''
        s = ''
        Lists = [i for i in range(1, n+1)]
        while k > 1:
            tmp1 = self.nFactorial(n-1)
            tmp2 = (k-1) // tmp1
            s = s + str(Lists[tmp2])
            del Lists[tmp2]
            k -= tmp1 * tmp2
            n -= 1
        for item in Lists:
            s = s + str(item)
        return s
    def nFactorial(self, n):
        '''求n的阶乘'''
        if n == 0 or n == 1:
            return 1
        result = 1
        while n > 0:
            result *= n
            n -= 1
        return result
```

