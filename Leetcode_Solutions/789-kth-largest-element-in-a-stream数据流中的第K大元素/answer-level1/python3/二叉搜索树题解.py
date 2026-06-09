### 解题思路
二叉搜索树卡片要求用BST来解这道题，所以就这么来写，当然是复杂了很多，但是可以把BST的几个知识点综合一起，还是比较好的。
BST中始终保留K个值，所以每次只要返回最小的值即可

### 代码

```python3
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.root = None
        self.size = 0
        for num in nums:
            self.root = self.insert_root(self.root, num)
            self.root = self.keep_k(self.root)

    def add(self, val: int) -> int:
        self.root = self.insert_root(self.root, val)
        self.root = self.keep_k(self.root)
        return self.get_min()
    
    def insert_root(self, root, num):
        if not root:
            self.size += 1
            return TreeNode(num)
        if root.val >= num:
            root.left = self.insert_root(root.left, num)
        else:
            root.right = self.insert_root(root.right, num)
        return root

    def keep_k(self, root):
        if self.size <= self.k:
            return root
        if not root:
            return None
        elif root.left:
            root.left = self.keep_k(root.left)
        else:
            self.size -= 1
            if not(root.left or root.right):
                root = None
            else:
                root.val = self.succ(root)
                root.right = self.deleteNode(root.right, root.val)
        return root
        

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        if root.val == key:
            if not (root.left or root.right):
                root = None
            elif root.right:
                root.val = self.succ(root)
                root.right = self.deleteNode(root.right, root.val)
            else:
                root.val = self.prev(root)
                root.left = self.deleteNode(root.left, root.val)
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            root.right = self.deleteNode(root.right, key)
        return root

    def succ(self, root):
        right = root.right
        while right.left:
            right = right.left
        return right.val
    
    def prev(self, root):
        left = root.left
        while left.right:
            left = left.right
        return left.val

    def get_min(self):
        cur = self.root
        while cur.left:
            cur = cur.left
        return cur.val

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```