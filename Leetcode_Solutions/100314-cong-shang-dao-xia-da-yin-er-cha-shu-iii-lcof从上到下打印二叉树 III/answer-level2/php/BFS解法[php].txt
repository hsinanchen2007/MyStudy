### 解题思路
记录层级，最后反转一下就ok

### 代码

```php
//https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
        if(empty($root)) return $res;
        $queue = new SplQueue();
        $queue->enqueue([1=>$root]);
        while(!$queue->isEmpty()){
            $data = $queue->dequeue();
            foreach ($data as $k=>$node){
                $res[$k][]=$node->val;
                if($node->left != null){
                    $queue->enqueue([$k+1=>$node->left]);
                }
                if($node->right != null){
                    $queue->enqueue([$k+1=>$node->right]);
                }
            }
        }

        //最后反转一下
        foreach ($res as $k=>$v){
            if($k%2==0){
                $res[$k] = array_reverse($res[$k]);
            }
        }

        return $res;
    }
}


```