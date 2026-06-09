# 题目要点：
1. BST，左子数比右子数小
2. 要求k个最接近target的结点值

# 解法一：非递归解法
解题思路：非递归二叉树搜索模板，在res赋值的时候判断是否属于k个target的接近值
```python3
def closestKValues_3(self, root: TreeNode, target: float, k: int) -> List[int]:
        # 解法3:非递归方法
        if not root:
            return
        DONE = 1 # 已读结点
        UNDO = 0 # 未读结点
        res = []
        stack = [(root, UNDO)]
        while stack:
            node, status = stack.pop()
            if not node:
                continue
            if status == UNDO:
                stack.append((node.right, UNDO))
                stack.append((node, DONE))
                stack.append((node.left, UNDO))
            elif status == DONE:
                if k > len(res):
                    res.append(node.val)
                elif abs(res[0] - target) > abs(node.val - target):
                    res.pop(0)
                    res.append(node.val)
        return res   
```

# 解法二：递归解法 + 双指针
解题思路：因为是BST，所以左边结点小于右边结点，中序遍历后是一个有序的数组，中序遍历（左-根-右），中序遍历后再使用二分查找k个最接近targte的值
```python3
def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        if not root:
            return
        res = []
        self.inorder(root, res)
        if k >= len(res):
            return res
        print(res)
        index = self.binary_search(res, target)
        if index == -1:
            return []
        print(index)
        result = []
        left = index - 1
        right = index + 1
        for i in range(k):
            result.append(res[index])
            if left >= 0 and right < len(res):
                if abs(res[left] - target) > abs(res[right] - target):
                    index = right
                    right += 1
                else:
                    index = left
                    left -= 1
            elif left >= 0:
                index = left
                left -= 1
            elif right < len(res):
                index = right
                right += 1
        return result

    # 1. 递归的定义
    def inorder(self, root, res):
        # 2. 递归的出口
        if not root:
            return
        # 3. 递归的拆解，中序遍历：左-》根-》右
        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)
```

# 解法三：
解题思路：在中序遍历过程中比较root.val和target的大小，当res里面还没有k个值时，都将val放进res里面
```python3
def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        if not root:
            retrun 
        # 解法2:中序遍历（左-根-右），遍历过程中判断是否已经在res并且比较第0个值与target
        res = []
        self.inorder(root, target, k, res)
        return res
        
    def inorder(self, root, target, k, res):
        if not root:
            return
        self.inorder(root.left, target, k, res)
        if k > len(res):
            res.append(root.val)
        elif abs(res[0] - target) > abs(root.val - target):
            res.pop(0)
            res.append(root.val)
        else:
            return
        self.inorder(root.right, target, k, res)
```