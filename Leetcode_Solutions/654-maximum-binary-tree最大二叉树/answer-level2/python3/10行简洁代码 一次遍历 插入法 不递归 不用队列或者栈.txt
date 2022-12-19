类似于插入法。维护一个最大化树，只遍历一次数组。对于每个元素，插入后保证还是一个最大化的树。不用搜索全部子树，只需要考虑右边的节点。

利用dummy节点简化代码逻辑。每次的具体逻辑：
1）搜索：从头结点开始比较，如果插入的元素小，就移动到右子节点继续搜索，不考虑左边的节点。
2）插入：假定n是要插入的节点，p是父节点，c是要插入的节点。这里分2种情况方便讲解：
2.1）添加：如果c是None，那n就是父节点的右子树。
2.2）替换：如果c不是None，那c就是n的左子树，然后n是父节点的右子树。
代码里可以合并这2种情况，具体如下。
```
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        dummy = TreeNode(0)
        for e in nums:
            p, c = dummy, dummy.right
            while c and c.val > e:
                p, c = c, c.right
            n = TreeNode(e)
            n.left, p.right = c, n
        return dummy.right
```


