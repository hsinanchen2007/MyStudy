### 解题思路
当没有下级节点时结束遍历，当节点值不相同时结束遍历返回false

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
    int count = 0;
    boolean back = true;
    public boolean isUnivalTree(TreeNode root) {
        count = root.val;
        recyle(root);
        return back;
    }
    public void recyle(TreeNode treeNode){   
       if(!back || treeNode == null){
            return;
       }
        if(treeNode.val != count){
            back = false;
            return;
        }
        recyle(treeNode.left);
        recyle(treeNode.right);
    }
}
```