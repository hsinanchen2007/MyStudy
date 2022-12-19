代码如下:
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None: return [] #排除空
        ans =  []
        stack =  [[root]] #将栈初始化为root节点
        while stack != [[]]:
            ans_temp = []
            stack_temp = []
            current_nodes = stack.pop()
            for current_node in current_nodes: #遍历这一层所有的节点
                ans_temp.append(current_node.val) #将这个节点的值加入ans_temp
                if current_node.left:stack_temp.append(current_node.left) #有左或右节点,则将节点加入栈
                if current_node.right:stack_temp.append(current_node.right)
            
            stack.append(stack_temp) #将下一层要遍历的元素放入栈中
            ans.append(ans_temp) #将这一层所有值放入答案
        return ans
```
