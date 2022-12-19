### 解题思路
递归对比两棵树的节点

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null&&q==null){//都为null
            return true;
        }else if((p==null&&q!=null)||(p!=null&&q==null)){//只有一棵树的节点为null
            return false;
        }else if(p.val!=q.val){//都不为null且节点的值不相等
            return false;
        }
        //继续往下遍历
        return isSameTree(p.left,q.left)&&isSameTree(p.right,q.right);
    }
}
```