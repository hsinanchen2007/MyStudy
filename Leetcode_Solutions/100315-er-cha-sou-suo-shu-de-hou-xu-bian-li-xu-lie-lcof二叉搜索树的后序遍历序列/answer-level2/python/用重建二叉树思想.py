### 解题思路
我们可以根据二叉树搜索树这个条件，获得一颗树的中序遍历。
根据数据结构课程的所学，已知前中后序中的两组遍历，均可以重建二叉树。
我们利用这个思路，如果能重建，则为true，反之为false。
根据后序遍历的最后一个数字，我们可以知道根节点
如果我们在递归中发现根节点不在inorder内，则返回false


### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def helper(inorder: List[int], postorder: List[int]):
            if not inorder: return True
            try:
                index = inorder.index(postorder[-1])
            except:
                return False
            return helper(inorder[:index], postorder[0:index]) and \
                helper(inorder[index+1:], postorder[index:-1])

        inorder = sorted(postorder)  
        return dfs(inorder, postorder)







```