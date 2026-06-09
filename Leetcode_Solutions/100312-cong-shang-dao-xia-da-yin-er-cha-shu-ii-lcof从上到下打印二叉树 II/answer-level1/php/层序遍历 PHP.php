### 解题思路
迭代思路
一次将每层数据放到队列（先入先出）

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
        //层序遍历
        $res = $arr = [];//模拟队列
        if($root ==null) return $res;
        array_push($arr,$root);//将根节点放入队列头部
        while($count = count($arr)){
           $tmp = [];
           for($i=0;$i<$count;$i++){
                $node = array_shift($arr);//先入先出
                $tmp[] = $node->val;
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
           }
           array_push($res,$tmp);
        }
        return $res;
    }
}
```

### 解题思路
递归思路

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
        //层序遍历
        $res = $arr = [];
        $this->helper($root,0,$res);
        return $res;
    }

    function helper($root,$level,&$res){
        if($root ==null) return ;
        if($level==count($res)){
            $res[$level] = []; 
        }
        array_push($res[$level],$root->val);
        $this->helper($root->left,$level+1,$res);
        $this->helper($root->right,$level+1,$res);
    }

}
```