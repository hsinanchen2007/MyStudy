### 解题思路
多加了一个参数、判断叶子节点；其它还是在树的遍历上面衍生的代码

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

    private int res = 0;

    public void preorder(TreeNode node, int val){
        if(node == null)
            return;
        if(node.left == null && node.right == null){
            val = val * 10 + node.val;
            this.res = this.res + val;
            return;
        }
        else{
            val = val * 10 + node.val;
            preorder(node.left, val);
            preorder(node.right, val);
        }
    }

    public int sumNumbers(TreeNode root) {
        preorder(root, 0);
        return this.res;
    }
}
```