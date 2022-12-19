### 解题思路
此处撰写解题思路

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
    public String smallestFromLeaf(TreeNode root) {
        ArrayList<String> list = new ArrayList<>();
        dfs(root, "",list);
        list.sort(String::compareTo);
        return list.get(0);
    }

    private void dfs(TreeNode root, String s, ArrayList<String> list) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            s = s + (char)(root.val + 'a');
            list.add(new StringBuilder(s).reverse().toString());
            return;
        }
        s = s + (char)(root.val + 'a');
        dfs(root.left, s, list);
        dfs(root.right, s, list);
    }
}
```