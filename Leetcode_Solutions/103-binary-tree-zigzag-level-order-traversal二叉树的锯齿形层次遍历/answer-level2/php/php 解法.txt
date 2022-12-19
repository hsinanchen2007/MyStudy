[在102题答案](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/php-jie-fa-by-andfly-10/)基础上增加逆序判断level%2==0
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function zigzagLevelOrder($root) {
        if($root === null) return [];
        $res = [];
        $this->helper($root,0,$res);
        return $res;
    }
    
    function helper($node,$level,&$res){
        if(count($res) == $level) $res[$level] = [];
        if(fmod($level,2)==0){
            array_push($res[$level],$node->val);
        }else{
            array_unshift($res[$level],$node->val);
        }
        if($node->left!==null) $this->helper($node->left,$level+1,$res);
        if($node->right!==null) $this->helper($node->right,$level+1,$res);
    }
}
```
