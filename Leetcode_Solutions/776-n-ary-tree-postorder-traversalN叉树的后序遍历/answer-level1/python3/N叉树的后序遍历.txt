### 解题思路
我的思路：
和二叉树的后续遍历解法相同, 给出递归和迭代写法.
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码
递归
```
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        result = []

        def postHelper(root):
            if not root:
                return None
            children = root.children
            for child in children:
                postHelper(child)
            result.append(root.val)

        postHelper(root)
        return result
```

迭代
```
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return None
        stack_run = [root]
        result = []
        while stack_run:
            node = stack_run.pop()
            result.append(node.val)
            children = node.children
            for child in children:
                if child:
                    stack_run.append(child)
        result.reverse()
        return result
            


```