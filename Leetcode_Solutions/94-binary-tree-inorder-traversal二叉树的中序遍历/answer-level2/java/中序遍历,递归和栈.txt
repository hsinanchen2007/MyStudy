### 解题思路
中序遍历,左根右
使用栈的思路,先将左子树全部压到栈中,然后弹出栈中元素比如树1,2,3,4,5,6,7,将左子树压栈,栈中元素是4,2,1栈顶是4,弹出,记录对应值,判断栈顶元素右子树是否为空,如果不为空将右子树压栈,并且将对应节点的所有左子树压栈,知道找到左右都为空的节点,然后依次弹出,记录值即可
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    //递归
    // public List<Integer> inorderTraversal(TreeNode root){
    //     List<Integer> result=new ArrayList<>();
    //     inorderTraversal(root,result);
    //     return result;
    // }
    // private void inorderTraversal(TreeNode root,List<Integer> result){
    //     if(root==null){
    //         return;
    //     }
    //     inorderTraversal(root.left,result);
    //     result.add(root.val);
    //     inorderTraversal(root.right,result);
    // }

    //栈
    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<Integer> res = new LinkedList <> ();
        Stack <TreeNode> stack = new Stack <> ();
        TreeNode curr=root;
        while(curr!=null||!stack.isEmpty()){
            //将所有左子树压栈
            while(curr!=null){
                stack.push(curr);
                curr=curr.left;
            }
            //弹出栈顶元素
            TreeNode node=stack.pop();
            //记录值
            res.add(node.val);
            //如果右子树不为空
            if(node.right!=null){
                //赋值给curr,下一轮继续压左子树到栈中
                curr=node.right;
            }
        }
        return res;
    }
}
```