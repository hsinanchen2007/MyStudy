### 解题思路


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
    List<String> list = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<String> binaryTreePaths(TreeNode root) {
        DFS(root);
        return list;
    }

    public void DFS(TreeNode root){
        // 递归的终止条件
        if (root == null) return;

        // 本级递归需要进行的操作
        path.add(root.val);
        // 到达叶子节点，到达这条路的终点
        if (root.left == null && root.right == null){
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < path.size(); i++) {
                sb.append(path.get(i));
                if (i != path.size()-1){
                    sb.append("->");
                }
            }
            //  sb.toString()
            list.add(sb.toString());
        }
        DFS(root.left);
        DFS(root.right);
        path.remove(path.size()-1);

    }
}
```