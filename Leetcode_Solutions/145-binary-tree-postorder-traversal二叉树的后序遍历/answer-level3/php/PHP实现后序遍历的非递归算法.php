```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    function postorderTraversal($root) {
        $ans=[];       //用于返回后序遍历结果
        $myStack=[];  //后序遍历的非递归算法需要用到栈空间
        $flag=null;  //用来标识回退是从右孩子还是左孩子
        while((sizeof($myStack)) || ($root!=null))
        {
            if($root!=null)
            {
                array_push($myStack,$root);
                $root=$root->left;
            }
            else
            {
                $root=end($myStack);    //取栈顶元素没有出栈
                if(($root->right!=null)&&($root->right!=$flag)) //右孩子存在且没有访问过，访问右侧孩子
                {
                    $root=$root->right;
                }
                else
                {
                    array_pop($myStack);
                    array_push($ans,$root->val);
                    $flag=$root;
                    $root=null;
                }
            }
        }
        return $ans;
    }
}
```
