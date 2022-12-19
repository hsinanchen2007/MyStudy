### 解题思路
之前一直想复杂了，以为是将 root.left 和 root.right 入队列时，需要颠倒一下位置。
但后来才想到，基于上一题，只需要将收集好所有单层节点值的 tmp 变量进行一下左右颠倒就可以了。

当输出的 result 变量一不小心写入了 TreeNode， 而不是 TreeNode.val 时，就会报比较复杂的错误，这是由于后台程序检测结果是否正确时，会将 TreeNode 与 int 值比较，导致复杂的错误。
之前在上一题[113. 路径总和 II gelthin-这一题值得细细思考](https://leetcode-cn.com/problems/path-sum-ii/solution/gelthin-zhe-yi-ti-zhi-de-xi-xi-si-kao-by-gelthin/)也碰到过
 



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        isOdd = 0  
        queue = [root]
        result = []
        while queue:
            tmp = []
            for i in range(len(queue)):
                x = queue.pop(0)
                tmp.append(x.val)
                if x.left:
                    queue.append(x.left)
                if x.right:
                    queue.append(x.right)
            if isOdd:
                tmp = tmp[::-1]  ##从第 0 行开始， 当为奇数行反转一下
            result.append(tmp)
            isOdd = (isOdd+1)%2
        return result



        
```