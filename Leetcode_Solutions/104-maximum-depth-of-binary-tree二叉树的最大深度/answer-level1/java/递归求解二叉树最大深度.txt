### 解题思路
***二叉树最大深度 = 1 + max(左子树最大深度， 右子树最大深度)；***
当树根节点为null，深度为0

### 代码

```java
class Solution {
    public int maxDepth(TreeNode root) {
        return getMaxDepth(root);
    }

    public int getMaxDepth(TreeNode node){
        if(node == null){
            return 0;
        }
        return Math.max(1 + getMaxDepth(node.left), 1 + getMaxDepth(node.right));
    }
}
```