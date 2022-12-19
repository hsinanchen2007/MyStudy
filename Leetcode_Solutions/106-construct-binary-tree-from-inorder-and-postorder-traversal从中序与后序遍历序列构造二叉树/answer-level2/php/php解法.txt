![微信截图_20190920144959.png](https://pic.leetcode-cn.com/70282272fde2d67908e2c83abe599c78b4b4c137d65717ae98d66ee78a85e3fd-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190920144959.png)

和[105题解法](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/php-jie-fa-by-andfly-12/)思路一致，区别在优先构建左子树还是右子树
```
class Solution {

    /**
     * @param Integer[] $inorder
     * @param Integer[] $postorder
     * @return TreeNode
     */
    function buildTree($inorder, $postorder) {
        $this->inorder = $inorder;
        $this->postorder = $postorder;
        $this->inmap = array_flip($inorder);
        $this->postindex = count($postorder)-1;
        return $this->helper(0,count($inorder)-1);
    }
    
    private $inmap; //反转中序数组中所有键以及它们关联的值
    private $postindex; // 后序参数索引
    private $inorder;
    private $postorder;
    
    function helper($instart,$inend){
        if($instart > $inend) return null;
        $nodeval = $this->postorder[$this->postindex];
        $inindex = $this->inmap[$nodeval];
        $node = new TreeNode($nodeval);
        $this->postindex--;
        $node->right = $this->helper($inindex+1,$inend);
        $node->left = $this->helper($instart,$inindex-1);
        return $node;
    }
}
```
