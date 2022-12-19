### 解题思路
采用递归题解，分两次递归，首先内部递归判断两个子树是否相等，外部递从头节点开始，切换子树，直到找到相等子树，或者递归完成，无法找到相等子树。
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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        TreeNode start = s;
        if(compareTree(start, t)) {
            return true;
        } else {
            if (start.left != null) {
                if (isSubtree(start.left, t)) {
                    return true;
                }
            }

            if (start.right != null) {
                if (isSubtree(start.right, t)) {
                    return true;
                }
            }
            
            
        }
        

        return false;
        
    }

    public boolean compareTree(TreeNode master, TreeNode compare) {
        if (master != null && compare != null) {
            if (master.val == compare.val) {
                if(!compareTree(master.left, compare.left)) {
                    return false;
                }
                if(!compareTree(master.right, compare.right)) {
                    return false;
                }
            } else {
                return false;
            }
                
        } else if (master == null && compare != null) {
            return false;
        } else if (master != null && compare == null) {
            return false;
        }
        
        

        return true;
    }
}
```