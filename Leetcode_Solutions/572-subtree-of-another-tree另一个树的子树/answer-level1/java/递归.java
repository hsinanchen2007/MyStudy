### 解题思路
找到与子树相同的节点则根据节点进行递归判断

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
        if(s == null || t == null){
            return false;
        }

        return(find(s, t));

        
    }

    public boolean find(TreeNode s, TreeNode t){
        if(s == null){
            return false;
        }
        if(s.val == t.val){
            boolean result = isEq(s, t);
            if(result){
                return result;
            }
        }
        if(find(s.left, t) || find(s.right, t)){
            return true;
        }
        return false;
    }

    public boolean isEq(TreeNode s, TreeNode t){
        if(s== null && t == null){
            return true;
        }
        if(s == null || t == null){
            return false;
        }
        if(s.val != t.val){
            return false;
        }
        return isEq(s.left, t.left) && isEq(s.right, t.right);
    }

}
```