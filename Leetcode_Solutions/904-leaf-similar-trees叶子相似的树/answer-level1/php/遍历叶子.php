
#### 通过遍历叶子，比较俩棵树的叶子形成的字符串是否相等。

#### PHP代码实现

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
     * @param TreeNode $root1
     * @param TreeNode $root2
     * @return Boolean
     */
    function leafSimilar($root1, $root2) {
        $str1 = $this->getLeaf($root1);
        $str2 = $this->getLeaf($root2);
        if ($str1 == $str2) {
            return true;
        } else {
            return false;
        }
    }
    
    function getLeaf($root, $str = '') {
        if ($root->left == null && $root->right == null) {
            $str = $str.$root->val;
            return $str;
        }
        
        $str = $this->getLeaf($root->left, $str);
        return $this->getLeaf($root->right, $str);
    }
}
```