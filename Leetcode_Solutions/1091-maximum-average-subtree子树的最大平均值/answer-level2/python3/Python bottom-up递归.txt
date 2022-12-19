自底向上，每次返回数字总和和当前位置的节点总数。
```
class Solution(object):
    def maximumAverageSubtree(self, root):
        
        def ave(root):
            if not root:
                return 0, 0
            left = ave(root.left)
            right = ave(root.right)
            nowNum = (left[1] + right[1]) + 1
            nowAve = float(root.val + left[0] + right[0]) / nowNum
            res.append(nowAve)
            return nowAve*nowNum, nowNum
        
        res = []
        ave(root)
        return max(res)
```
