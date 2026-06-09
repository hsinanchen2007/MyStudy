执行用时 :12 ms, 在所有 PHP 提交中击败了87.50%的用户
内存消耗 :16.1 MB, 在所有 PHP 提交中击败了100.00%的用户
```
class Solution {

    /**
     * @param TreeNode $root
     * @param Integer $sum
     * @return Integer[][]
     */
    function pathSum($root, $sum) {
        $res = [];
        $path = [];
        $this->helper($root,$sum,$path,$res);
        return $res;
    }
    
    function helper($node,$sum,&$path,&$res){
        if($node == null) return ;
        $sum -= $node->val;
        $path[] = $node->val;
        if($node->left == null && $node->right == null && $sum==0){
            $res[] = $path;
        }
        $this->helper($node->left, $sum, $path, $res);
        $this->helper($node->right, $sum, $path, $res);
        array_pop($path);
    }
}
```
