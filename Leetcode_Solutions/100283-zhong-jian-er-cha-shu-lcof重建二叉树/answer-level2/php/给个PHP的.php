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
        $result = $this->build($preorder,$inorder,0,count($preorder)-1,0,count($inorder)-1);
        return $result;
    }

    function build($preorder,$inorder,$preorderStart,$preorderEnd,$inorderStart,$inorderEnd){
        //前序的首位就是根节点
        if($preorderStart>$preorderEnd || $inorderStart >$inorderEnd){
            return null;
        }
        $treeNode = new TreeNode($preorder[$preorderStart]);
        //找到根节点在中序的位置
        for ($i=$inorderStart;$i<=$inorderEnd;$i++){
            if($preorder[$preorderStart] == $inorder[$i]){
                break;
            }
        }
        //左边节点数量
        $len = $i-$inorderStart;
        $treeNode->left = $this->build($preorder,$inorder,$preorderStart+1,$preorderStart+$len,$inorderStart,$i-1);
        $treeNode->right = $this->build($preorder,$inorder,$preorderStart+$len+1,$preorderEnd,$i+1,$inorderEnd);
        return $treeNode;
    }
}