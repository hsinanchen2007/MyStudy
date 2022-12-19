### 解题思路
由於要判斷是否爲bst搜索二叉樹,即判斷當前節點
    1.是否大於左樹的最大值
    2.且滿足小於右樹的最小值
若同時滿足兩條即爲合法的bst
於是對於每個節點除了記錄當前節點的值,還要記錄左樹最大和右樹最小.

初始化時要將右樹初始爲最小,左樹初始化爲最大,保證初始情況下
即bottom的時候(葉子結點時)滿足合法bst

如果是合法bs則更新最大值..且返回當前最大值和左樹最大 和 右樹最小

反正如果不是合法bst,則將結果設定爲必然爲非法bst的情況,持續返回

### 代码

```python3
class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        def h(n):
            nonlocal ans
            if not n:
                return 0,hi,lo
            v1,l1,l2 = h(n.left)
            v2,r1,r2 = h(n.right)
            if n.val > l2 and n.val < r1:
                ans = max(ans,n.val + v1 + v2)
                return n.val+v1+v2,min(n.val,l1),max(n.val,r2)            
            return 0,lo,hi
        ans = 0
        lo,hi = float('-inf'),float('inf')
        h(root)
        return ans
        
```