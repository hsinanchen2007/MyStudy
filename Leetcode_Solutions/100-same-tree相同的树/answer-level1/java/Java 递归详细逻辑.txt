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
        if(p == null && q == null){// 如果两个节点都不存在，说明相等
            return true;
        }else if(p == null || q == null){// 如果某一个节点不存在，说明不相等
            return false;
        }else{// 如果两个节点都存在
            if (p.val == q.val){ // 如果这两个节点的值都一样
                // 判断左右子树
                return (isSameTree(p.left,q.left) && isSameTree(p.right,q.right));
            }else{// 如果值不一样，说明不相等
                return false;
            }
        }
    }
}
```