![image.png](https://pic.leetcode-cn.com/7f422e8b1636dcceceb2c27391a1dacaa6fada1c88b23b269a5aec3e3c951c0f-image.png)

把后序数组翻转后（这里称作逆后序数组），两个数组的首元素就都可以直接做树根了。

因为前序后序遍历的左右是相反的，然后检查第二个元素，如果第二个元素相同，说明只有一个子树存在，这里默认生成为左子树。

如果第二个元素不同，那先序数组的第二个元素就是左子树的树根，逆后序数组的第二个元素就是右子树的树根，根据两个树根的值来切割两个数组，进行递归生成树。

```python []
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        def f(pr, po):
            if pr:
                t = TreeNode(pr[0])             #首元素生成树根
                if pr[1: ]:
                    if pr[1] == po[1]:          #次元素相同说明只有一棵子树
                        t.left = f(pr[1: ], po[1: ])
                    else:
                        i = pr.index(po[1])     #查找右树根值在前序数列的坐标
                        j = po.index(pr[1])     #左根后序列坐标，因为数据比较小，写成这样方便理解，也可以写成j = len(pr) + 1 - i
                        t.left = f(pr[1: i], po[j: ])   #递归生成左右子树
                        t.right = f(pr[i: ], po[1: j])
                return t                        #返回树节点指针
        return f(pre, post[:: -1])
```
