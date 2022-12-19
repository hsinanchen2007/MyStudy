一直在苦恼复制子树怎么快速做到
然后突然意识到其实共用子树的话，外部程序其实是检查不出来节点是被共用了的
这样就很简单了
```
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if (n == 0):
            return []
        return self.Generate(1, n)
    
    def Generate(self, l, r):
        if l > r:
            return [None]
        result = []
        for i in range(l, r+1):
            L_result = self.Generate(l, i-1)
            R_result = self.Generate(i+1, r)
            for lv in L_result:
                for rv in R_result:
                    nt = TreeNode(i)
                    nt.left = lv
                    nt.right = rv
                    result.append(nt)
        return result
```
