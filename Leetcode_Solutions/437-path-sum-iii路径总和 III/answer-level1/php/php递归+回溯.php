### 解题思路
php递归+回溯，见注释

执行用时 :72 ms, 在所有 PHP 提交中击败了92.00% 的用户
内存消耗 :36.2 MB, 在所有 PHP 提交中击败了12.50%的用户

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

    /**
     * @param TreeNode $root
     * @param Integer $sum
     * @return Integer
     */
    function pathSum($root, $sum) {
        return $this->pathSumHandle($root, $sum, [], 0);
    }

    //递归+回溯，$arr 保存路径；$p 指向当前终点节点
    function pathSumHandle($root, $sum, $arr = [], $p) {
        if($root == null) {
            return 0;
        }

        $tmp = $root->val;
        $n = $tmp == $sum ? 1 : 0;
        //回溯路径和
        for($i=$p-1;$i>=0;$i--) {
            $tmp += $arr[$i];
            if($tmp == $sum) {
                $n++;
            }
        }

        //保存路径
        $arr[$p] = $root->val;

        $n1 = $this->pathSumHandle($root->left, $sum, $arr, $p+1);
        $n2 = $this->pathSumHandle($root->right, $sum, $arr, $p+1);

        return $n+$n1+$n2;
    }
}
```