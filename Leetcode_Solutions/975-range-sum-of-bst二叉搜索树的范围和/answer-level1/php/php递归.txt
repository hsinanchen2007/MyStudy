class Solution {

    /**
     * @param TreeNode $root
     * @param Integer $L
     * @param Integer $R
     * @return Integer
     */
    function rangeSumBST($root, $L, $R) {
        if ($root == null) {
            return 0;
        }
        if ($root->val < $L) {
            return $this->rangeSumBST($root->right, $L, $R);
        }
        if ($root->val > $R) {
            return $this->rangeSumBST($root->left, $L, $R);
        }
        return $root->val + $this->rangeSumBST($root->left, $L, $R) + $this->rangeSumBST($root->right, $L, $R);
    }
}