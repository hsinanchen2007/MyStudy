## 思路
从后序遍历序列 postorder 的后面开始检查边界问题，最后一个是根节点..
检查根节点值是否在上下界之间，如不是直接返回 False。
只要左子树的值小于当前节点值且大于之前的下界，同时,右子树的值大于当前节点值且小于之前的上界就没问题。
        
## 代码
```
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        return self.check_bound(postorder, float('-inf'), float('inf'))
        
    def check_bound(self, postorder, low, high):
        if not postorder:        # 空返回 True
            return True

        # 检查当前节点的边界
        cur = postorder.pop()
        if cur < low or cur > high:
            return False

        # 得到左右子树的切分点, i 及其往左都是左子树的
        i = len(postorder) - 1
        while i >= 0 and postorder[i] > cur:
            i -= 1
        
        left_in_bound = self.check_bound(postorder[:i+1], low, cur)    # 左子树的上界收缩为 cur， 下界不变
        right_in_bound = self.check_bound(postorder[i+1:], cur, high)  # 右子树的下界收缩为 cur，上界不变

        return left_in_bound and right_in_bound
```
