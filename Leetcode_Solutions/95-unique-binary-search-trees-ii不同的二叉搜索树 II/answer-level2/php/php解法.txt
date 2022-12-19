```
class Solution {

    /**
     * @param Integer $n
     * @return TreeNode[]
     */
    function generateTrees($n) {
        if($n==0) return [];
        return $this->helper(1,$n);
    }
    
    function helper($start,$end){
        $res = [];
        if($start>$end){
            $res[] = null;
            return $res;
        }
        for($i=$start;$i<=$end;$i++){
            $subLefts = $this->helper($start,$i-1);
            $subRights = $this->helper($i+1,$end);
            foreach($subLefts as $subLeft){
                foreach($subRights as $subRight){
                    $node = new TreeNode($i);
                    $node->left = $subLeft;
                    $node->right = $subRight;
                    $res[] = $node;
                }
            }
        }
        return $res;
    }
}
```
