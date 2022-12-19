


class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    private $ret = 0;
    function longestUnivaluePath($root) {
        
        $this->helper($root);
        return $this->ret;
    }

    private function helper($root) {
        if($root === null) return 0;
        $leftNode = $root->left;
        $rightNode = $root->right;
        $left = $this->helper($leftNode);
        $right = $this->helper($rightNode);

        $rl = $rr = 0;
        if($leftNode !== null && $root->val === $leftNode->val) {
            $rl = $left +1;
        }
        if($rightNode !== null && $root->val === $rightNode->val) {
            $rr = $right +1;
        }

        $this->ret = $rl+$rr > $this->ret ? $rl+$rr : $this->ret ;  
        return max($rl,$rr);
    }
}