### 解题思路
二叉搜索树后续遍历的性质，最后一位是根节点，从前往后找到第一个比root大的节点，该节点分割左右子树，判断右子树是不是全部大于当前根节点，然后递归左右子树。

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        #二叉搜索树后续遍历的性质，最后一位是根节点，从前往后找到第一个比root大的节点，该节点分割左右子树 
        
        def dfs(tmp):
            if len(tmp) <=1:
                return True
            
            for i,c in enumerate(tmp):
                l = len(tmp)

                if c>=tmp[-1]:
                    for k in tmp[i:]:
                        if k < tmp[-1]:
                            return False
                    return dfs(tmp[:i]) and dfs(tmp[i:l-1])

            return True
        
        return dfs(postorder)
```