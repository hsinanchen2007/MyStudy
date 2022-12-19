### 解题思路
迭代版本1：数组模拟队列（先入先出）

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
    function levelOrder($root) {
        $res = $arr = [];
        if($root ==null){
            return $res;
        }
        array_push($arr,$root);
        $level = 0;
        while($count = count($arr)){
            for($i=$count;$i>0;$i--){
                $node = array_shift($arr);//先入先出
                $res[$level][] = $node->val;
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
            }
            $level++;
        }
        return $res;
    }
}
```

### 解题思路2
迭代版本2：使用php  SqlQueue

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
    function levelOrder($root) {
        $res = [];
        $arr = new SplQueue();
        if($root ==null){
            return $res;
        }
        $arr->enqueue($root);
        $level = 0;
        while($count=$arr->count()){
            for($i=$count;$i>0;$i--){
                $node = $arr->dequeue();//删除第一位
                $res[$level][] = $node->val;
                if($node->left !=null) $arr->enqueue($node->left);
                if($node->right !=null) $arr->enqueue($node->right);
            }
            $level++;
        }
        return $res;
    }
}
```


### 解题思路3
递归版本

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
    function levelOrder($root) {
        $res = [];
        $this->level($root, 0, $res);
        return $res;
    }

    function level($root,$level,&$res){
        if($root == null){
            return null;
        }
        $res[$level][]= $root->val;
        $level++;
        if ($root->left !=null) {
            $this->level($root->left, $level, $res);
        }
        if ($root->right !=null) {
            $this->level($root->right, $level, $res);
        }
    }
}
```