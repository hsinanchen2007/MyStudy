### 解题思路
我的思路：
考察的是树的层次遍历,原来有这种写法啊哈哈哈,代码参考题解中的一个小姐姐.稍微改了一下实现.
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        result = []
        current = [root]
        
        while current:
            cur_layer_val = [] #当前层存储的值
            next_layer_node = [] # 下一层的节点，无论存不存在都可以存
            for node in current:
                if node:
                    cur_layer_val.append(node.val)
                    next_layer_node.extend([node.left,node.right])
            if cur_layer_val:
                result.append(cur_layer_val)
            current = next_layer_node
        result.reverse()
        return result


```