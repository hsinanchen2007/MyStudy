### 解题思路
此处撰写解题思路
屏幕快照 2020-03-31 14.11.23
![image.png](https://pic.leetcode-cn.com/42b692bf2670d467c21cd9a70ebaf6bde551cec2cb02ec78344f2aaa4557122d-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue, res = collections.deque(), []    
        queue.append(root)
        flag = True # 奇数层为True,偶数层为false
        while queue:
            tmp = collections.deque()   # 保存每一层结果的双端队列。用list也可以，右端插入append，左端插入insert
            for i in range(len(queue)):
                node = queue.popleft()
                if flag:    # 若为奇数层，从右往左保存
                    tmp.append(node.val)
                else:       # 若为偶数层，从左往右保存
                    tmp.appendleft(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            flag = not flag
            res.append(list(tmp))   # 注意最后把deque转化为list
        return res

```