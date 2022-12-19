### 解题思路
回溯法（深度优先搜索）思路的简单描述是：把问题的解空间转化成了图或者树的结构表示，然后使用深度优先搜索策略进行遍历，遍历的过程中记录和寻找所有可行解或者最优解。
回溯法按深度优先策略搜索问题的解空间树。首先从根节点出发搜索解空间树，当算法搜索至解空间树的某一节点时，先利用剪枝函数判断该节点是否可行（即能得到问题的解）。如果不可行，则跳过对该节点为根的子树的搜索，逐层向其祖先节点回溯；否则，进入该子树，继续按深度优先策略搜索。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        lst=[]
        
        def dfs(s,left,right):
            if left==right==0:
                lst.append(s)
                return
            if right<left:
                return
            if left>0:
                dfs(s+'(',left-1,right)
            if right>0:
                dfs(s+')',left,right-1)
        dfs('',n,n)
        return lst
```