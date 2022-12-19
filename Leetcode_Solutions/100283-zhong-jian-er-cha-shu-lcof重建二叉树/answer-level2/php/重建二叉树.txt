### 解题思路
此处撰写解题思路

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
     * @param Integer[] $preorder
     * @param Integer[] $inorder
     * @return TreeNode
     */
    function buildTree($preorder, $inorder) {
        if(empty($preorder) || empty($inorder)){
            return null;
        }
        $root=new TreeNode($preorder[0]);
        $arrStack=[];
        array_push($arrStack,$root);

        $inJ=0;

        for($i=1;$i<count($preorder);$i++){
            $pVal=$preorder[$i];

            $node=end($arrStack);
            if($node->val==$inorder[$inJ]){
                while(!empty($arrStack) && $inorder[$inJ]==end($arrStack)->val){
                    $node=array_pop($arrStack);
                    $inJ++;
                }
                $node->right=new TreeNode($pVal);
                array_push($arrStack,$node->right);
            }else{
                $node->left=new TreeNode($pVal);
                array_push($arrStack,$node->left);

            }
        }
        return $root;
    
    }
}
```