### 解题思路

思路很簡單
    1.首先判斷當前節點是否爲空,返回None
    2.dfs遞歸的基線情況是,到達業節點即left和right都是None,
    若深度更深,則此時更新狀態
***由於是優先遞歸地調用左子樹,所以最深的一層最左邊的節點被優先記錄
其右邊同深度的節點,由於深度相同不會更新記錄的值slef.ans.***


### 代码
```python3
class Solution:
    def __init__(self):
        self.dep = -1
        self.ans = -1
    def findBottomLeftValue(self, root: TreeNode) -> int:
        def dfs(node,level):
            if not node:
                return 
            if not node.left and not node.right and level>self.dep:
                self.dep = level
                self.ans = node.val
            dfs(node.left,level+1)
            dfs(node.right,level+1)
            return self.ans

        return dfs(root,0)
    
        
```