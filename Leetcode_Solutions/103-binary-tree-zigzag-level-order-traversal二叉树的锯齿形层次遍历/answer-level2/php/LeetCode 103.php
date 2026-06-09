### 解题思路
1、参考层次遍历
2、在层数为偶数的时候翻转数组

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
     * @return Integer[][]
     */
    function zigzagLevelOrder($root) {
        $res = $arr = [];
        if($root ==null){
            return $res;
        }
        array_push($arr,$root);
        $levelArr = [];
        $level = 1;
        while($count = count($arr)){
            for($i=$count;$i>0;$i--){
                $node = array_shift($arr);//先入先出
                $levelArr[] = $node->val;
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
            }

            if ($level%2 == 0) {//偶数就翻转数组
                $levelArr = array_reverse($levelArr);
            }
            array_push($res, $levelArr);
            $level++;
            $levelArr = [];
        }
        return $res;
    }
}
```

### 解题思路
递归算法：层数+1判断是否偶数，如果是就从数组开头插入数据（从右->左）反之 从数组尾部插入数据(从左->右)

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
     * @return Integer[][]
     */
    function zigzagLevelOrder($root) {
        $res  = [];
        $this->level($root, 0, $res);
        return $res;
    }

    function level($root,$level,&$res){
        if($root == null){
            return null;
        }
        if($level >= count($res)){
            $res[$level] = [];
        }
        if(($level+1)%2==0){
            array_unshift($res[$level],$root->val);
        }else{
            array_push($res[$level],$root->val);
        }
        if ($root->left !=null) {
            $this->level($root->left, $level+1, $res);
        }
        if ($root->right !=null) {
            $this->level($root->right, $level+1, $res);
        }
    }
}
```