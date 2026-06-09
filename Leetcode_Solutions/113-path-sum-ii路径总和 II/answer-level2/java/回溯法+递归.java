### 解题思路
用时1ms
回溯法
递归遍历树
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

    List<List<Integer>> paths = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null){
            return paths;
        }else{
            path.add(root.val);
            if(sum - root.val == 0 && root.left == null && root.right == null){
                paths.add(new ArrayList<>(path));
            }
            pathSum(root.left, sum - root.val);
            pathSum(root.right, sum - root.val);
            path.remove(path.size() -1);
            return paths;
        }
    }
}
```