### 解题思路
此处撰写解题思路
因为二叉树的特性，采用中序遍历数组，从右边最大的节点开始往回计算，每一个节点相当于加上
前面节点的和

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

    private int lastValue = 0;

    //因为二叉树的特性，采用中序遍历数组，从右边最大的节点开始往回计算，每一个节点相当于加上
    //前面节点的和
    public TreeNode bstToGst(TreeNode root) {
        if(null == root){
            return null;
        }

        //先遍历右子树
        bstToGst(root.right);

        root.val += lastValue;
        lastValue = root.val;


        //遍历左子树
        bstToGst(root.left);

        return root;
    }
}
```