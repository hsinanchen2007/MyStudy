### 解题思路
核心思想：一旦存在第二小的值，就不用继续往下遍历了，因为子节点大于等于父节点。

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
    int result = -1;
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return result;
        }
        findSecondMinimumValue(root, root.val);
        return result;
    }

    private void findSecondMinimumValue(TreeNode root, int min) {
        if (root == null) {
            return;
        }
        
        if (result == -1) {
            if (root.val < min) {                      // 1 此处高亮
                min = root.val;
                result = min;

            } else if (root.val > min) {
                result = root.val;
            } else {
                findSecondMinimumValue(root.left, min);
                findSecondMinimumValue(root.right, min);
            }
        // 一定存在第二小值
        } else {

            if (root.val > min && root.val < result) {  // 2 此处高亮
                result = root.val;
            }
            else if (root.val < min) {
                min = root.val;
                result = min;
            }
            else {
                findSecondMinimumValue(root.left, min);
                findSecondMinimumValue(root.right, min);
            }
        }
    }
}
```