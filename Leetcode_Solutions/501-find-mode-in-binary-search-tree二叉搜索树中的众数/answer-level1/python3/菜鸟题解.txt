### 解题思路
先广度遍历，统计所有元素出现的个数，存放于字典中；
然后找到字典中values最大的值，并将其对应的key保存于list

执行用时 :
44 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :
16.6 MB, 在所有 python3 提交中击败了98.82%的用户
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        queue = [root]  #定义一个栈，用于广度遍历
        d = {} #定义字典，用于存放元素以及其出现的次数
        while queue:
            node = queue.pop(0)

            if node.val not in d:   #将元素加入到字典中，并统计其出现的个数
                d[node.val] = 1
            else:
                d[node.val] +=1

            if node.left is not None:  #分别遍历当前节点的左右元素
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        
        m = max(d.values())  #找到元素最多出现的次数
        l = []
        for k,v in d.items():
            if v == m:
                l.append(k) #将最多出现的元素加入到列表中
        return l
```