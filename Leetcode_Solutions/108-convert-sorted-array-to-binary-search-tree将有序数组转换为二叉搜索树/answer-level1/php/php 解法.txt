```
class Solution {

    /**
     * @param Integer[] $nums
     * @return TreeNode
     */
    function sortedArrayToBST($nums) {
        return $this->helper($nums,0,count($nums)-1);
    }
    
    function helper($nums,$left,$right){
        if($left>$right) return null;
        $mid = $left + floor(($right - $left)/2);
        $node = new TreeNode($nums[$mid]);
        $node->left = $this->helper($nums,$left,$mid-1);
        $node->right = $this->helper($nums,$mid+1,$right);
        return $node;
    }
}
```
