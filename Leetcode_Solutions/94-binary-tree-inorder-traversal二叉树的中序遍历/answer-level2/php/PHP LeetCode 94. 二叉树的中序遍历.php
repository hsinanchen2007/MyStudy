### 解题思路
1、仔细观察二叉树的中序遍历 左->根->右
2、其实是优先遍历左子树，以及左子树的右节点，然后根
3、设定当前叶子节点；

循环：
4、如果节点不为空的话，就入栈（先入后出)，并且设置节点未当前节点的左子树
5、如果节点未空的话，就出栈，并且将值存在结果数组，并设置节点未节点右子树

案例：[1,null,2,3]
为例：
1. cur为根节点，入栈，并且设置cur为左子树，其实是null
2. cur为null,出栈（1），$res[0] = 1;cur = 1的右子树
3. cur为2,入栈，并且设置cur为左子树,也是3
4. cur为3,入栈，并且设置cur为左子树，null
5. cur为null，出栈（3），$res[1] = 3;cur = 3的右子树
6. cur为null，出栈（2），$res[2] = 2;cur = 2的右子树
7. cur为null，栈空循环结束
8. echo $res;[1,3,2] 


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
     * @return Integer[]
     */
    function inorderTraversal($root) {
        $arr = $res = [];
        if ($root == null) {
            return $res;
        }
        //设置当前节点
        $cur = $root;//根节点
        while($cur!=null || !empty($arr)){
            if($cur!=null){ //如果当前叶子节点不为null
                array_push($arr, $cur);
                $cur = $cur->left;
            }else{
                $cur = array_pop($arr);
                $res[] = $cur->val;
                $cur = $cur->right;
            }
        }
        return $res;
    }
}
```