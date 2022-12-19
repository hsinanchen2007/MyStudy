数学归纳法:

直接上草稿了
![IMG_2189.JPG](https://pic.leetcode-cn.com/fdf68414fbda3476484b37034109ee0f472c97eb825ce2aa6608f36a1cdae682-IMG_2189.JPG)

用了递归，比较慢。应该是可以直接求出通项公式用数学方法算的。


`


    class Solution:
        def superEggDrop(self,K: int, N: int) -> int:
            ts = [0] * K
            ts.append(0)
            for i in range(1, K + 1):
                ts[i] = ts[i - 1] * 2 + 1
            if N <= ts[-1]:
                for i in ts:
                    if i >= N:
                        m = ts.index(i)
                        break
            else:
                ans = ts[-1]
                m = K
                while N > ans:
                    m += 1
                    ans = self.bss(K, m)
            return m

        def ass(self,i):
            ts = 1
            for i in range(1, i):
                ts = ts * 2 + 1
            return ts

        def bss(self,i, j):
            if i == j:
                return self.ass(i)
            elif i == 1 and j > i:
                return j
            else:
                ans = self.bss(i, j - 1) + self.bss(i - 1, j - 1) + 1
            return ans
`
另外借鉴了精选题解和评论的思路优化了一个解题方式：
鸡蛋够用：直接计算步长
鸡蛋不够用： 动态规划
但是执行速度比原来提升并不明显（可能是因为测试用例里大部分都是鸡蛋不够用的情况。）