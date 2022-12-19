### 解题思路

### 本题主要思路：

1.利用卡特兰数求解，G(n) = ∑i∈[0,n] G(i)*G(n-i-1)
2.主要通过切点i,判断i的左右是否存在构成新的节点条件的值。
   2.1 对于左边：是否存在x满足start<=x<i的值，如果存在则递归继续切分，继续判断，知道不满足返回[None]。
   2.2 对于右边：是否存在x满足i<x<=end的值，如果存在则递归继续切分，继续判断，直到不满足返回[None]]。
3.通过for循环其实有着计算是个笛卡尔积的作用，left*right种可能。在循环中依次生成新的节点可能性，添加到all_trees列表中，
最后输出的列表将会包含所有中可能。因为该动态规划，采用自顶而下的方式。


**注：这里用列表存储，因为继续切分得到的结果可能有多个，为了将这些结果合并，需采用for循环。**


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        # 如果 为空树
        if not n:
           return []

        def new_trees(start,end):
            if start > end:
                return [None]

            all_trees = []
            # 针对(start,end)中的每一个i进行切分，也就是求G(i),判断左右是否有节点，通过start和end比较
            for i in range(start,end+1):
                # 左子树
                left_trees = new_trees(start,i-1)
                # 右子树
                right_trees = new_trees(i+1,end)
                
                for left in left_trees:
                    for right in right_trees:
                        tree = TreeNode(i)
                        tree.left = left
                        tree.right = right
                        all_trees.append(tree)
            # print(all_trees)
            # 注：每次递归进入的子树的all_trees都是不一样的。可以通过打印print()查看控制台的输出，这样更容易理解具体的思路。
            return all_trees

        return new_trees(1,n)
```