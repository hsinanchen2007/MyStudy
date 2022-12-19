### 解题思路
DFS求出所有路径、然后二进制转十进制，求和即可

### 代码

```java

class Solution {
    List<String> list = new ArrayList<>();

    public int sumRootToLeaf(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs(root, "");
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum += Integer.parseInt(list.get(i), 2);
        }
        return sum;
    }

    private void dfs(TreeNode root, String s) {
        if (root.left == null && root.right == null) {
            list.add(s + root.val);
            return;
        }
        if (root.left != null) {
            dfs(root.left, s + root.val);
        }
        if (root.right != null) {
            dfs(root.right, s + root.val);
        }
    }
}
```