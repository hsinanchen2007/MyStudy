### 解题思路
二叉搜索树，中序遍历的结果是有序的数组。
如果是 左-中-右，则结果是递增的数组；
如果是 右-中-左，则结果是递减的数组。

利用这个性质，我们可以求出第k大数字。

### 代码

```php
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

    private $res = [];
    /**
     * @param TreeNode $root
     * @param Integer $k
     * @return Integer
     */
    function kthLargest($root, $k) {
        $this->helper($root);
        return $this->res[$k-1];
    }

    function helper($root){
        if($root==null) return;
        $this->helper($root->right);
        array_push($this->res,$root->val);
        $this->helper($root->left);
    }
}
```