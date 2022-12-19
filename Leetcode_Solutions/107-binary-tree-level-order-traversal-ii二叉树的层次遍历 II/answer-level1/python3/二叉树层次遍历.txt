
```python
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans = []
        q = [root]               
        while q:                                  
            cur_level_val = []       # 记录当前层的元素的值
            next_level_node = []     # 记录下一层的节点
            for node in q:           # 循环每一个当前层节点
                if node:             # 节点不为空:则 将节点的值不断加入当前层值; 将当前节点的左右子节点没别加入下层节点 list
                    cur_level_val.append(node.val)   
                    next_level_node += [node.left, node.right]
            if cur_level_val:                # 如果当前层值 list 不为空,则加入到 返回列表
                ans.append(cur_level_val)    
            q = next_level_node              # 更新 q    
        return ans[::-1]                     # 由于要从后到前的顺序,故返回翻转的 ans
```