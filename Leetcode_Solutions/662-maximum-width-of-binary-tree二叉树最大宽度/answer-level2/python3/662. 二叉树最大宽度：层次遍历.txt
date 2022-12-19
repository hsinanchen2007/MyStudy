![image.png](https://pic.leetcode-cn.com/c2e1b7ab79de4714e9495807816c096a3d06aa5fa454c6dde4847af25f734832-image.png)

用一个队列记录某层的坐标和节点，下一个轮队列由这一轮队列的节点生成，首末元素的坐标差就是该层的最大宽度，相当于是宽搜。

```python [group]
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        que = [[0, root]]   #起始坐标为0，节点为根节点
        ans = 1
        while que:
            ans = max(ans, que[-1][0] - que[0][0] + 1)
            tmp = []                        #下一轮队列
            for i, q in que:
                if q.left:
                    tmp += [[i * 2, q.left]]#坐标节点生成
                if q.right:
                    tmp += [[i * 2 + 1, q.right]]
            que = tmp
        return ans
```
