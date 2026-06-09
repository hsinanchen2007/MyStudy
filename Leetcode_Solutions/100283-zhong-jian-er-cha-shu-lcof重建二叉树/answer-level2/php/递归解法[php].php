### 解题思路
比如对于前序遍历[3,9,20,15,7]，中序遍历[9,3,15,20,7]
1、前序遍历结果的第一个元素肯定是根节点的值，也即3；
2、此时，找到3在中序遍历中的index(即index=1)，得到中序遍历的左子树为[9],右子树为[15,20,7]；进一步根据中序遍历的左右子树，得到前序遍历的左子树为[9],右子树为[20,15,7];
3、如此循环，重复第1、2步骤，构建完整的二叉树。

### 代码

```php
class TreeNode {
    public $val = null;
    public $left = null;
    public $right = null;
    function __construct($value) { $this->val = $value; }
}

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
     * @param Integer[] $preorder
     * @param Integer[] $inorder
     * @return TreeNode
     */
    function buildTree($preorder, $inorder) {
        if(empty($preorder) || empty($inorder)) return null;
        return $this->helper($preorder,0,count($preorder)-1,$inorder,0,count($inorder)-1);
    }

    function helper($pre_order,$pre_start,$pre_end,$in_order,$in_start,$in_end){
        //前序遍历的第一个元素就是根节点
        $root_value = $pre_order[$pre_start];
        //初步建立二叉树，但此时left、right指向的都是null
        $root = new TreeNode($root_value);

        //递归终止条件，如果start==end，证明是最后1个元素，应该返回节点
        if($pre_start == $pre_end || $in_start == $in_end){
            return $root;
        }

        //根节点在中序遍历中的位置
        $root_index = array_search($root_value,$in_order);

        //中序遍历的左子树
        $in_order_left = array_slice($in_order,0,$root_index);
        //中序遍历的右子树
        $in_order_right = array_slice($in_order,$root_index+1);

        //前序遍历的左子树
        $pre_order_left = array_slice($pre_order,1,$root_index);
        //前序遍历的右子树
        $pre_order_right = array_slice($pre_order,$root_index+1);

        //节点左子树建立
        if(!empty($pre_order_left) && !empty($in_order_left)){
            $root->left = $this->helper($pre_order_left,0,count($pre_order_left)-1,$in_order_left,0,count($in_order_left)-1);
        }

        //节点右子树建立
        if(!empty($pre_order_right) && !empty($in_order_right)){
            $root->right = $this->helper($pre_order_right,0,count($pre_order_right)-1,$in_order_right,0,count($in_order_right)-1);
        }
        return $root;
    }
}
```