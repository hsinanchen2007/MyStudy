思路：
    对于一棵满二叉树，若其高度为l，则节点个数为2^l-1个节点。   
    递归求解。  
    1. 首先从根节点开始，沿左子树的左节点一路向下，得到整棵二叉树的最大深度h_l（因为是完全二叉树，所以最左侧叶节点的高度可以代表整棵树的最大高度）。  
    2. 其次计算根节点右子树最左侧子节点的高度h_r。  
        若h_l = h_r，则说明左子树为一满二叉树，可通过公式2^h_l计算其节点个数。  
        若h_l > h_r（h_l = h_r + 1），则说明右子树为满二叉树，可通过公式2^h_r计算其节点个数。  
    3. 递归计算另一棵子树的节点数目。  
    终止条件：  
    当前节点高度为子树高度h_l，h_r均为0，说明其左右节点均为空，没有进入循环调节，即到达最后的叶节点。  

```
class Solution(object):        
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        
        h_l, h_r = 0, 0
        # 计算当前节点左子树的最大高度
        curRoot = root
        while curRoot.left:
            h_l += 1
            curRoot = curRoot.left
        # 计算当前节点右子树的最大高度
        curRoot = root
        if curRoot.right:
            h_r += 1
            curRoot = curRoot.right
            while curRoot.left:
                h_r += 1
                curRoot = curRoot.left
        
        # 左右子树最大高度相同，说明左子树为满二叉树，在右子树继续递归求解     
        if h_l == h_r:
            sumNodes_r = self.countNodes(root.right)
            sumNodes_l = 2**h_l - 1
        # 左子树高度更高，说明右子树为满二叉树，在左子树继续递归求解   
        if h_l == h_r + 1:
            sumNodes_l = self.countNodes(root.left)
            sumNodes_r = 2**h_r - 1
         
        # 返回左子节点个数+右子节点个数+当前根节点   
        return sumNodes_l + sumNodes_r + 1
```
