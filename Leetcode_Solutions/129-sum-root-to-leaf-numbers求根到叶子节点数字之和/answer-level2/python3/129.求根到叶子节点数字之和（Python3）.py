### 解题思路
这里采用三种方法：
1. 递归
2. 迭代（栈+dfs）
3. 迭代（队列+dfs）
#### 递归
采用dfs遍历从根到每个叶子节点的路径，每当到达叶子节点时，将从根到叶子节点路径所代表的数加到结果中。
#### 代码
```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.res = 0
        self.dfs(root, 0)
        return self.res

    def dfs(self, root, value):
        if root:
            self.dfs(root.left, value * 10 + root.val)
            self.dfs(root.right, value * 10 + root.val)
            # 如果到达了叶子节点，将该数加到结果中
            if not root.left and not root.right:
                self.res += value * 10 + root.val
```
#### 迭代（栈+dfs）
采用dfs遍历从根到每个叶子节点的路径，每当到达叶子节点时，将从根到叶子节点路径所代表的数加到结果中。
与递归不同的是，我们使用栈保存节点和值。算法如下：
1. 将根节点压入栈中
2. 如果栈不为空
    - 弹出栈顶元素和值
    - 如果节点不为空且到达了叶子节点，将从根到该叶子所表示的数加到结果中
    - 如果节点不为空且节点左孩子不为空，将左孩子入栈
    - 同理，将右孩子入栈
3. 返回结果

#### 代码
```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack,res = [(root,root.val)],0  # 使用栈保存节点和值
        while stack:
            node,value = stack.pop()  # 弹出节点和值
            if node:
                if not node.left and not node.right: # 到达了叶子节点
                    res += value
                if node.left:
                    stack.append((node.left,value * 10 + node.left.val))
                if node.right:
                    stack.append((node.right,value * 10 + node.right.val))
        return res
```
#### 迭代（队列+dfs）
```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue,res = collections.deque([(root,root.val)]),0
        while queue:
            node,value = queue.popleft()  # 出队
            if node:
                if not node.left and not node.right: #如果到达了叶子节点，加到结果中
                    res += value
                if node.left:
                    queue.append((node.left,value * 10 + node.left.val))
                if node.right:
                    queue.append((node.right,value * 10 + node.right.val))
        return res
```

