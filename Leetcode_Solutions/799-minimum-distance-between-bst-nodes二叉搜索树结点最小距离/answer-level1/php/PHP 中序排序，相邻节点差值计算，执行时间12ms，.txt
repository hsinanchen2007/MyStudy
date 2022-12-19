结题思路：
1. 二叉树相邻节点差值计算：
- 无非就是当前节点与左节点，当前节点与右节点的做差；
- 二叉树的中序遍历刚好就是依次取出左子树、根、右子树；
2. 最小值
- 这个就很简单了，将每次计算出来的相邻节点的差值与全局的最小值做对比，更新全局最小值即可；
```
/**
 * 已经定义好的二叉树节点的结构
 * class TreeNode {
 *     public $val = null;    # 节点的值
 *     public $left = null;   # 该节点的左节点
 *     public $right = null;  # 该节点的右节点
 *     function __construct($value) { $this->val = $value; }
 * }
 */

class Solution {
    
    private $pre = 100; # 前一节点的值，-- 初始设置为100是因为题目中说明了节点值最大为100，初始值不重要；
    private $min = 100; # 最小值，-- 初始设置为100是因为题目中说明了节点值最大为100，差值最大为100，初始值不重要；

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function minDiffInBST($root) {
        $this->inOrder($root);
        return $this->min;
    }
    
    /**
     * 中序遍历二叉树，并计算二叉树中相邻节点的最小差值；
     * @param TreeNode $node 节点
     * return Integer 返回值不重要，只是为了退出递归
     */
    function inOrder($node) {
        if(empty($node)) {
            return 0;
        }
        # 中序遍历
        $this->inOrder($node->left); // 左子树
        // 比较相邻节点
        $this->min = min([$this->min, abs($node->val-$this->pre)]);
        $this->pre = $node->val;
        $this->inOrder($node->right); // 右子树
        return 1;
    }
}
```
