
![image.png](https://pic.leetcode-cn.com/9fc70f8f6c70fe83c8aaed9e62cdebedb3f3ac07c6720aaf068b34b2ff99f182-image.png)



```

'''
递归进行操作
如果当前子树的根是需要被删除的，向上一层返回None
如果当前子树不删除，从其子树回溯到当前子树根的时候，向上一层返回自己的根
在回溯回到每个子树根时候，修改该子树的左右子节点为两个子树处理的返回结果
如果某个子树根出现了自己不删除但是父节点被删除情况，当前子树根一定是
最后森林里面一个子树的根

'''


from typing import List, Set
class Solution:

    def solve(self, root: TreeNode, parent_del: bool, del_set: Set[int], ans: List[TreeNode]):  # parent_del表示父节点是不是要删除的
        if root is None:
            return root

        if root.val not in del_set:
            root.left = self.solve(root.left, False, del_set, ans)
            root.right = self.solve(root.right, False, del_set, ans)

            if parent_del:
                ans.append(root)
            return root
        else:
            root.left = self.solve(root.left, True, del_set, ans)
            root.right = self.solve(root.right, True, del_set, ans)
            return None

    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        ans = []
        del_set = set(to_delete)

        self.solve(root, True, del_set, ans)
        return ans
```
