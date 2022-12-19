思路：就是利用中序遍历的结果是从小到大的排序的结果，通过维护3个变量以及返回的结果数组。
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
     * @return Integer[]
     */
    private $now=0; //当前相同元素出现次数计数器
    private $prev=null; //上一个考察的元素
    private $max=0; //最大出现次数计数器
    private $ret=[];    //返回的结果集

    function findMode($root) {
        $this->inOrder($root);
        return $this->ret;
    }

    //中序遍历
    function inOrder($root){
        if($root==null){
            return;
        }

        $this->inOrder($root->left);
        if($this->max==0){
            //中序遍历的第一个元素
            $this->prev=$root->val;
            $this->max++;
            $this->now++;
            $this->ret[]=$root->val;
        }else{
            //判断是否是重复元素
            if($root->val==$this->prev){
                $this->now++;   //如果是重复元素，now++
            }else{
                $this->prev=$root->val; //如果不是重复元素，更新prev
                $this->now=1;                //now重置为1
            }

            if($this->now>$this->max){
                //当now大于max时，更新max
                $this->max=$this->now;
                $this->ret=[];  //重置ret
                $this->ret[]=$this->prev;   //将最新的元素压入ret
            }else if($this->now==$this->max){
                $this->ret[]=$this->prev;   //当now和max相等时，将值压入ret
            }
        }            
        $this->inOrder($root->right);
    }
}
```
