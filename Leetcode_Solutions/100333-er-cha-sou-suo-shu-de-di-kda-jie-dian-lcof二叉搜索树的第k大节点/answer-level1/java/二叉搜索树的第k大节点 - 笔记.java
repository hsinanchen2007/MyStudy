### 解题思路
由于二叉搜索树可使用中序遍历，拿到对应的倒数第K大。可使用counter计算

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

    private int counter = 0;
    private int result = -1; 

    /**
    * 由于二叉搜索树可使用中序遍历，拿到对应的倒数第K大。可使用counter计算
    **/
    public int kthLargest(TreeNode root, int k) {
        // 初始化k
        this.counter = k;
        // 中序遍历递归
        recur(root, k);
        return result;
    }

    private void recur(TreeNode root, int n) {
        if (root != null) {
            // 先遍历右子树
            recur(root.right, counter);
            // 处理
            if (counter == 1) {
                counter--;
                result = root.val;
                return;
            }
            counter--;
            // 遍历左子树
            recur(root.left, counter);
        }
    }
}
```