题目说是返回最大深度是有误解的,示例中树深度应该是2,因为第一层深度是0.
# 两种解法
- 第一种是递归求解左右子树高度,然后高度+1就是树高.递归遍历分前序遍历、中序遍历、后序遍历,公式:树高=max(左子树高,右子树高)+1
- 第二种层次遍历,记录每层节点,查找每层节点的左右节点是否存在.当存在层节点则高度+1,不存在则返回当前树高
```
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function maxDepth($root) {
        if (empty($root)) {return 0;}
        $level = 1;
        $tree = [$root]; // 将树装进数组后方便遍历对象
        while (true) {
            $node = [];
            foreach ($tree as $value) {
                if ($value->left != null) {
                    $node[] = $value->left;
                }
                if ($value->right!= null) {
                    $node[] = $value->right;
                }
            }
            # 无子节点表示已遍历完树的层数,直接返回层数
            if (count($node) == 0) {
                return $level;
            }
            $tree = $node;
            $level++;
        }
        
    }
}
```
