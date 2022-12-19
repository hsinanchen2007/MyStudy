### 解题思路
先序遍历，标记父节点和祖父节点，祖父节点为true时候，当前节点值累加

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
    public int sumEvenGrandparent(TreeNode root) {
        return preOrder(root,false,false,0);
    }
    private int preOrder(TreeNode node, boolean f, boolean g,int sum) {
        if (node == null) {
            return sum;
        }
        if (g){
            sum += node.val;
        }
        g = f;
        f = node.val % 2 == 0;
        sum += preOrder(node.left,f,g,0);
        sum += preOrder(node.right,f,g,0);
        return sum;
    }
}
```