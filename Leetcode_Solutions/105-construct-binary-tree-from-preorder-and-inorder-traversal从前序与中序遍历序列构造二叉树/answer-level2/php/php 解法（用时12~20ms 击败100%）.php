![微信截图_20190920141201.png](https://pic.leetcode-cn.com/4a8d31b8eedf636d08ac1b03f42aaad1aa1c59ad41389f903f17b6af8bb87e91-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190920141201.png)

```
class Solution {

    /**
     * @param Integer[] $preorder
     * @param Integer[] $inorder
     * @return TreeNode
     */
    function buildTree($preorder, $inorder) {
        $this->preorder = $preorder;
        $this->inorder = $inorder;
        $this->inmap = array_flip($inorder);
        return $this->helper(0,count($inorder)-1);
    }
    
    private $inmap; //反转中序数组中所有键以及它们关联的值
    private $preindex = 0; // 前序参数索引
    private $preorder;
    private $inorder;
    
    function helper($instart,$inend){
        if($instart > $inend) return null;
        $nodeval = $this->preorder[$this->preindex];
        $inindex = $this->inmap[$nodeval];
        $node = new TreeNode($nodeval);
        $this->preindex++;
        
        $node->left = $this->helper($instart,$inindex-1);
        $node->right = $this->helper($inindex+1,$inend);
        return $node;
    }
}
```
