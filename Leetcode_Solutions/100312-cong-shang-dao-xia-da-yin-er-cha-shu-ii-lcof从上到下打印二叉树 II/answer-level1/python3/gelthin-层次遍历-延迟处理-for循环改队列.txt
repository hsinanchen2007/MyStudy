### 解题思路
同[主站 102 题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

##### 延迟处理经常忘了处理最后一组值


##### 在入队列时，加入此节点的深度即可。
[看了别人的解答](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/mian-shi-ti-32-ii-cong-shang-dao-xia-da-yin-er-c-5/)，似乎没有必要记录深度，只需要计算一下队列的长度即可
#### 在for 循环过程中 
+ for x in queue, 则 queue 不可变，否则直接报错，我之前在哪一题写栈的时候，就报错了
+ for i in range(len(queue)), 即使 queue 发生改变，也不会报错

[如果用 java 写](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/mian-shi-ti-32-ii-cong-shang-dao-xia-da-yin-er-c-5/279046)
+ for(int i =0; i< queue.size();i++)  会出错, 因为 queue.size() 在运行中变化
+ 应该用  for(inti=queue.size();i>0;i++)

``` python3
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res, queue = [], [root]
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.pop(0)
                tmp.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            res.append(tmp)
        return res





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
        result = []
        if root == None:
            return result
        queue = []
        queue.append([root, 0])
        tmp, h = [], 0

        while queue:
            A, j = queue.pop(0)
            if j == h:
                tmp.append(A.val)
            else:
                result.append(tmp)
                tmp = [A.val]
                h = j
            if A.left:
                queue.append([A.left, j+1])
            if A.right:
                queue.append([A.right, j+1])
        ### 这种延迟处理经常忘了最后一次累加
        result.append(tmp)

        return result
```
#### 无需记录深度的代码

``` python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root == None:
            return result
        queue = [root]

        while queue:
            tmp = []
            for i in range(len(queue)):
                A = queue.pop(0)
                tmp.append(A.val)
                if A.left:
                    queue.append(A.left)
                if A.right:
                    queue.append(A.right)
            result.append(tmp)

        return result    
```