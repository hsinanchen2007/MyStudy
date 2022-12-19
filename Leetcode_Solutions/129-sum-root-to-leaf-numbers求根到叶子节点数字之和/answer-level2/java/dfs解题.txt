### 解题思路
通过暂时存储所有根到当前dfs节点的数组，当到叶子节点时，保存结果

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
    LinkedList<Integer> list;
    int sum;
    public int sumNumbers(TreeNode root) {
        list = new LinkedList<>();
        if (root == null) {
            return 0;
        }
        sum = 0;
        dfs(root);
        return sum;
    }

    public void dfs(TreeNode node) {
        list.add(node.val);
        if (node.left == null && node.right == null) {
            add();
        }
        if (node.left != null) {
            dfs(node.left);
        }
        if (node.right != null) {
            dfs(node.right);
        }
        list.removeLast();
    } 

    public void add() {
        int base = 1;
        for (int i=list.size()-1;i>=0;i--) {
            sum = sum + list.get(i)*base;
            base = base*10;
        }
    }
}
```