# 一、递归解法
很容易想到使用“树的前序遍历”完成题目
所以有以下代码
```python []
def flatten(self, root: TreeNode) -> None:
        # 根->左->右的顺序处理结点
        if root!=None:
            process(root) 
            self.flatten(root.left)
            self.flatten(root.right)
```
用node.right作为node.next
很容易写出process(root)的过程：
```python []
            l,r=root.left,root.right
            root.left=None
            root.right=l
```
如果直接运行，你可以发现左子树遍历完成后并无右子树遍历结果，原因在于处理后的右子树并没有跟在左子树遍历结果后，即 单链表最后一个结点.right！=右子树处理后的单链表
所以我们需要在遍历左子树后对结果单链表最后一个结点进行处理，将右子树接到该结点后面
即endNode.next=右子树根节点
所以有如下代码（完整）：
```python []
class Solution:
    def flatten(self, root: TreeNode) -> None:
        if root!=None:
            # 处理root
            l,r=root.left,root.right
            root.left=None
            root.right=l
            # 处理root.left
            self.flatten(l)
            # 将root.right接到结果单链表后面
            if l!=None:
                while l.right!=None:
                    l=l.right
                l.right=r
            else:
                root.right=r
            # 处理root.right
            self.flatten(r)
```

# 二、迭代解法
对树型结构熟悉的话很容易想到递归解法，但题目要求原地展开，即空间复杂度为O(1)，故需要修改为迭代解法。
![image.png](https://pic.leetcode-cn.com/df0cd6c908cb9bd766567feda1e6400d1e860f3d74e1dce5540d8d40b91e9b20-image.png)

（不会用编辑器画树，尴尬...）
可以观察到，root.right是在root.left最右结点的后面，那么就可以有以下思路：
1. 若左子树==None，root指向其右子树
2. 否则l=root.left，找到该子树中最右结点r，使r.right=root.roght，同时root.right=l,r.left=None

代码如下：
```python []
    def flatten(self, root: TreeNode) -> None:
        while root:
            if not root.left:
                # 左子树为空，直接作为部分结果
                root = root.right
            else:
                # 处理左子树
                left = root.left
                while left.right: # 找到该子树的最右结点
                    left = left.right
                left.right = root.right # 根结点右子树接到该子树最右节点后
                root.right = root.left # 根节点左子树接到根节点后
                root.left = None # 根节点左子树置空，开始下一次while循环
``` 
P.s 第二种方法确实难想一些，且思路很绕，在纸上画图走走流程就能理解了

