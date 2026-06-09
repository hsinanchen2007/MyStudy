### 解题思路
第一次写写成递归了，不是很简洁。。。

用G(p)表示p个点的组合数
考虑有p个点，一个点作为root,那么他下面还要连接p-1个点
二叉树中点只能分布在左边或右边
排列组合思想，左右的点数只能分别为（0，p-1）,(1,p-2), ... ,(p-1,0)共p种情况
并且每个情况的组合数是左右分支的乘积
所以求和就是G(0)*G(p-1)+...+G(p-1)*G(0)

这里用一个数组记录下已经求得的p点情况的组合数

### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        self.ll = [1]
        def check(p):
            res = 0
            for i in range(p):
                if i<=len(self.ll)-1:
                    a = self.ll[i]
                else:
                    a = check(i)
                if (p-1-i)<=len(self.ll)-1:
                    b = self.ll[p-1-i]
                else:
                    b = check(p-1-i)
                res += a*b
            self.ll.append(res)
            return res
        check(n)
        return self.ll[-1]


```