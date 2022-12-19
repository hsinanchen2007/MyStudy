### 解题思路
第一步找到树的高度，推算最大宽度，并初始化一个动态数组，然后根据父节点和子节点的递归关系，
递归建立二叉树。

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
    List<List<String>> resultList;
    // 存储每个点在当前行的位置，根是0，往左为负，往右为正
    public List<List<String>> printTree(TreeNode root) {
        int height = getHeight(root);
        resultList = new ArrayList<>();
        for (int i=0;i<height;i++) {
            List<String> addedList = new ArrayList<>();
            for (int j=0;j<(1<<height)-1;j++) {
                addedList.add("");
            }
            resultList.add(addedList);
        }
        dfs(root, 0, 0, (1<<height)-1);
        return resultList;

    }

    public int getHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return 1+Math.max(getHeight(node.left), getHeight(node.right));
    }

    public void dfs(TreeNode node, int h, int l, int r) {
        if (node == null) {
            return;
        }
        int pos = (l+r)/2;
        resultList.get(h).set(pos, ""+node.val);
        dfs(node.left, h+1, l, (l+r)/2);
        dfs(node.right, h+1, (l+r)/2+1, r);
    }

}
```