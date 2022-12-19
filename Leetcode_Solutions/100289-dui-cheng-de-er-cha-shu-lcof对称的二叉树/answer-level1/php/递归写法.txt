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
     * @return Boolean
     */
    function isSymmetric($root) {
        return $this->isMirror($root, $root);
    }

    function isMirror($treeLeft, $treeRight) {
        if ($treeLeft == null && $treeRight == null) {
            return true;
        }
        if ($treeLeft == null || $treeRight == null) {
            return false;
        }
        return ($treeLeft->val == $treeRight->val) && $this->isMirror($treeLeft->left, $treeRight->right) && $this->isMirror($treeLeft->right, $treeRight->left);
    }
}