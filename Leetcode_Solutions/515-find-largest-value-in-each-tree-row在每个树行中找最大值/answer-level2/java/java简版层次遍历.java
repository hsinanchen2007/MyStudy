### 解题思路
层次遍历挺好写，用时长了点不过思路简单，每次一层，存住下一层，遍历取出最大val然后替换成下一层继续

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
    public List<Integer> largestValues(TreeNode root) {
        List<TreeNode> nodeList = new ArrayList<>();
        nodeList.add(root);
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        boolean flag = true;
        while (flag) {
            ans.add(nodeList.stream().max(Comparator.comparingInt(p -> p.val)).get().val);
            List<TreeNode> tempList = new ArrayList<>();
            for (TreeNode node : nodeList) {
                if (node.left != null) {
                    tempList.add(node.left);
                }
                if (node.right != null) {
                    tempList.add(node.right);
                }
            }
            if (tempList.isEmpty()) {
                flag = false;
            }
            nodeList.clear();
            nodeList.addAll(tempList);
        }
        return ans;
    }
}
```