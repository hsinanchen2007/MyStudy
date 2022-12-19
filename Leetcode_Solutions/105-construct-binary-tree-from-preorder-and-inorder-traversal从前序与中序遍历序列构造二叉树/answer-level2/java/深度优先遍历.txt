### 解题思路
我对这道题的理解很简单。
前序数组preorder的首位值就是整个树的根节点的值，以该值为参数创建一个节点：
TreeNode node = new TreeNode(preorder[0]);
然后在中序数组inorder中找与根节点值相等的下标i：
for(;i<inorder.length;i++){
            if(inorder[i] == node.val)break;
        }
这个i就会把中序数组inorder分为左右两部分，左边就是根节点的左子树，右边就是其右子树，执行深度遍历即可：node.left = buildTree(Arrays.copyOfRange(preorder,1,i+1),Arrays.copyOfRange(inorder,0,i));
        node.right = buildTree(Arrays.copyOfRange(preorder,i+1,preorder.length),Arrays.copyOfRange(inorder,i+1,inorder.length));
注意下标，copyOfRange函数是左闭右开，下标搞不定了自己用笔写写就会了。
然后就是递归结束条件了：
if(preorder.length==0||inorder.length==0)return null;
代码简洁。


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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length==0||inorder.length==0)return null;
         TreeNode node = new TreeNode(preorder[0]);
        int i=0;
        for(;i<inorder.length;i++){
            if(inorder[i] == node.val)break;
        }
        node.left = buildTree(Arrays.copyOfRange(preorder,1,i+1),Arrays.copyOfRange(inorder,0,i));
        node.right = buildTree(Arrays.copyOfRange(preorder,i+1,preorder.length),Arrays.copyOfRange(inorder,i+1,inorder.length));
        return node;
    }
}
```