### 一个完全二叉树：
```
输入: 
    1
   / \
  2   3
 / \  /
4  5 6

```

```
一 完全二叉树的性质：
1. 每个root都有两个子节点（二叉树是全满结构）
2. 最底层可以不全满，但要保证左边要先满
```
```
二 关于层数：完全二叉树的层数可以有两种写法，如果要计算除最后一层外，上面所有的层数（👇方法一）需要这样写：

while root.left:
    root = root.left
    level += 1
return level    --> level = 2

如果要计算所有的层数（👇方法二），需要这样写:
while root
    root = root.left
    level += 1
return level   ---> level = 3   

```
```
三 在二叉树上如何进行二分查找（搜索）
1. 对于式例二叉树最后一层进行二分搜索: left, right = 0, 2*2-1。此时，我们直接遍历完全二叉树的最后一层，首先我们先查找 mid 在不在这这一棵树上 mid = left + (right - left)//2 = 1 (index = 1 对应式例中5是否在树上)，如果查找到最底层，（这里就是要遍历d次的原因）发现node不为空，则说明该index= mid 对应的节点在树上存在，即：
            for _ in range(d):  # 查找d次 （d = 2) 
                mid = left + (right - left) // 2
                if idx <= mid:
                    node = node.left
                    right = mid
                else:
                    node = node.right
                    left = mid
2. 如果该mid在树上就left + 1, 因为二叉树性质2（👆）即：
            if exist(mid, d, root):
                left = mid + 1
            else:
                right = mid - 1
```
```
四 方法二比较好理解，简单的递归。
```

### 代码如下（👇）
#### 方法一
```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def countlevel(root):
            level = 0
            if not root: return 0
            while root.left:
                root = root.left
                level += 1
            return level
        
        def exist(idx, d, node):  # 在树上找 如果当前给的idx 小于mid 查找树的左边，大于就查找树的右边
            left, right = 0, 2 ** d - 1
            for _ in range(d):
                mid = left + (right - left) // 2
                if idx <= mid:
                    node = node.left
                    right = mid
                else:
                    node = node.right
                    left = mid
            return node is not None
        
        if not root: return 0
        d = countlevel(root)
        if d == 0: return 1
        left, right = 0, 2 ** d - 1
        while left <= right:  # 每次给exist的都是mid 再在树上找mid是否存在 
            mid = left + (right - left) // 2
            if exist(mid, d, root):
                left = mid + 1
            else:
                right = mid - 1
        return left + 2 ** d - 1
```
#### 方法二
```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        left_node = root
        right_node = root
        hl = hr = 0
        while left_node:
            left_node = left_node.left
            hl += 1
        while right_node:
            right_node = right_node.right
            hr += 1
        
        if hr == hl: return 2 ** hl - 1
        else:
            return 1 + self.countNodes(root.left)  + self.countNodes(root.right)
```
