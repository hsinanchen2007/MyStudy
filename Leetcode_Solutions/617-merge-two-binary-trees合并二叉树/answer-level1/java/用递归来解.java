### 解题思路
1、正常情况下，t1，t2节点均不为空，创建root节点，结点值为t1,t2节点值相加
  root的左子节点用t1,t2左子节点递归来解
  同理，root的右子节点用t1,t2右子节点递归来解
2、特殊情况，即t1,t2可能为空的情形
  若t1为空，则返回t2节点
  若t2为空，则返回t1节点
最后，返回root节点即得到结果。

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
        if (t1==null){
            return t2;
        }
        if (t2==null){
            return t1;
        }

        TreeNode root = new TreeNode(t1.val+t2.val);

        root.left = mergeTrees(t1.left, t2.left);
        root.right = mergeTrees(t1.right, t2.right);

        return root;
    }
}
```