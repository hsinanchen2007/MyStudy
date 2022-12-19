### 解题思路
只要有左或者右那就塞到List，List size增加 就代表有下一层，没增加 那就跑完了break掉，如果有增加的话就按照每次while开始时的size取下标把上一次的元素移除，最后遍历list 算个val的和

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
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class Solution {
    public int deepestLeavesSum(TreeNode root) {
        if (root == null) {
            return 0;
        }

        List<TreeNode> treeList = new CopyOnWriteArrayList<>();
        treeList.add(root);

        while (true) {
            int treeSize = treeList.size();
            for (TreeNode treeNode : treeList) {
                if (treeNode.left != null) {
                    treeList.add(treeNode.left);
                }
                if (treeNode.right != null) {
                    treeList.add(treeNode.right);
                }
            }
            if (treeSize == treeList.size()) {
                break;
            }
            if (treeList.size() > treeSize) {
                treeList.subList(0, treeSize).clear();
            }
        }
        return treeList.stream().mapToInt(node -> node.val).sum();
    }
}
```