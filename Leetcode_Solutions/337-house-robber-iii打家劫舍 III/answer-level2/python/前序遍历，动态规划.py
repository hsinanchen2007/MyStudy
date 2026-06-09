尝试解释下EndA的解答。

DFS函数返回一个数组，第一位代表不包括当前结点值的最大值，第二位代表包括当前结点的最大值。对树进行前序遍历，遍历到node结点。如果不选node结点，则其对应的最大值为max(l)+max(r)，此时需要各个情况，左右结点包括和不包括。如果选这个结点，则对应的最大值为cur.val+l[0]+r[0]。

最后返回根节点，DFS返回数组的最大值即可，即包括根节点与不包括根结点的最大值。

```python
class Solution:
    def DFS(self , cur):
        if not cur :
            return [0,0]
        
        l = self.dp(cur.left)
        r = self.dp(cur.right)
         
        return [max(l)+max(r),cur.val+l[0]+r[0]]
    def rob(self, root):
        return max(self.DFS(root))
```