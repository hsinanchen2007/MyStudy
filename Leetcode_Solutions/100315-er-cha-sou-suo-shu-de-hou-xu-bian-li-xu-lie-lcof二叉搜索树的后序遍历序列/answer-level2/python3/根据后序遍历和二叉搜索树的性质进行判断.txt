### 解题思路
根据后序遍历和二叉搜索树的性质进行判断：后序遍历的根为数组中最后一个数，二叉搜索树的左子树小于根，右子树大于根，迭代。直到所有的结点都满足该性质返回True
![下载 (7).png](https://pic.leetcode-cn.com/90b38a89bf74b5e23594016d9b65db7b1a79cca4ffd157b762c3e73bafdb35ed-%E4%B8%8B%E8%BD%BD%20\(7\).png)

### 代码

```
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder :
            return True
        def fuc(postorder):
            length = len(postorder)
            if length <= 1:
                return True
            root = postorder[length-1]
            left = []
            right = []
            #生成根节点的左右子树
           for i,point in enumerate (postorder): 
                if point < root:
                    left.append(point)
                else:
                    right = postorder[i:length-1]
                    break
###         右子树是否满足二叉树的性质
            for i in right:
                if i < root:
                    return False
###         左右子树遍历
            return fuc(left) and fuc(right)
        return fuc(postorder)


```