
最开始拿到这道题第一想法是递归，判断左子树和右子树相对于root的大小，但是二叉搜索树有个特征是右子树的所有值都应该比root大，左子树的所有值都应该比root小
如果单纯的递归的话，很容易出现以下的情况
```
    5
   / \
  1   6
     / \
    3   7
```


5满足左子树小，右子树大，6也满足左子树小右子树大
按照单纯递归这就是二叉搜索树，但是节点3就有问题，它虽然小于了父节点6，但是它小于了root节点5，但是3处于root的右子树内部，它应该比root更大才能成为一棵二叉搜索树
所以这个方法被否定

那么如果我递归判断的时候带上树的上下界呢？而且我只需要判断当前节点和上下界的大小，而不需要父节点和左右子树进行比较
如：
```
    5
   / \
  1   6
```

平常是用5去比较1和6，如果用上下界我就用1去比较5,6去比较5

上下界初始化为None，root进来我需要分别判断左子树和右子树是否为二叉搜索树，那么我需要传入对应的上下界
左子树需要更新上界upper，右子树需要更新下界lower
那么最初比较节点5的时候，发现上下界均为None，则不比较，然后递归判断左子树1和右子树6，左子树传入新的上界也就是当前节点的值5，右子树传入新的下界也是5
然后我在比较节点1的时候，需要和上下界比较，如果大于等于上界，或者小于等于下界，返回False
此时要注意一点，当上下界要不为None的时候才去判断大小
而且在有and判断的时候必须要用 if upper is not None 来进行判断，而不能用 if upper，因为upper和lower均为数值，数值的and计算，如果不为0均为1，为0则为0，会被判定为False，因而在下面这个例子出错
如：
   
```
    0
     \
      -1
```
当判断-1的时候，它的下界为0，判断if lower and root.val <= low的时候，因为lower为0，会被判为0而进不去if内层，于是判断出错

在比较完1之后，比较6，它的上界为None，下界为5，满足条件，继续递归，同时传入新的更新的上下界【注意：一定要传入更新的上下界，lower和upper要保持传递，不能传入None】

比较3的时候，它是6的左子树，所以上界为6，又带有原始的下界5，3不大于5，所以False，不为搜索二叉树

```
class Solution:
    
    def isValidBST(self, root: TreeNode) -> bool:
        return self.check(root, None, None)

        
    def check(self, root, lower, upper):
        if not root:
            return True
        if (lower is not None and root.val <= lower) or (upper is not None and root.val >= upper):
            return False
        
        return self.check(root.left, lower, root.val) and self.check(root.right, root.val, upper)
```
