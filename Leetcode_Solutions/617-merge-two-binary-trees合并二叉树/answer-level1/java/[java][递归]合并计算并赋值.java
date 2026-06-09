### 解题思路

递归合并两个树相同位置的节点。
1. 对应节点都不存在，返回 null
2. 对应节点有一个存在，则返回存在节点
2. 节点都存在，两值相加赋给 t1
3. 将子树返回的节点赋值给对应位置
4. 将新的节点返回。

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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null && t2 == null){
            return null;
        } else if (t1 == null){
            return t2;
        } else if (t2 == null){
            return t1;
        }

        int value = t1.val + t2.val;
        TreeNode leftNode = mergeTrees(t1.left,t2.left);
        TreeNode rightNode = mergeTrees(t1.right,t2.right);
        t1.val = value;
        t1.left = leftNode;
        t1.right = rightNode;
        return t1;
    }
}
```