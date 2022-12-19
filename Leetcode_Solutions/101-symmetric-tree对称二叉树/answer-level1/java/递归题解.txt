### 解题思路
思路：首先判断前置条件根节点不为空，随后递归方法，进行多重判断，假如值相等，继续递归，因为是镜像对称，所以递归参数为左节点的左节点和右节点的右节点，以及左节点的右节点和右节点的左节点。</br>

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
    public boolean isSymmetric(TreeNode root) {
        if(root != null) {
            return check(root.left, root.right);
        } else {
            return true;
        }
        
    }

    private boolean check(TreeNode leftRoot, TreeNode rightRoot) {
        if (leftRoot != null && rightRoot != null) {
            if(leftRoot.val == rightRoot.val) {
                return check(leftRoot.left, rightRoot.right) && check (leftRoot.right, rightRoot.left);
            } else {
                return false;
            }
        } else if (leftRoot == null && rightRoot == null) {
            return true;
        } else {
            return false;
        }
    }
}
```