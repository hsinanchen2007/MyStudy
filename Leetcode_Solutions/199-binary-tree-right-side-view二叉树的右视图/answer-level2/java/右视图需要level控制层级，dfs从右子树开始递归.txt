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
    List<Integer> list = new ArrayList<>();
    Map<Integer, Integer> map = new HashMap<>();
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null) return new ArrayList<>(0);
        dfs(root, 1);
        return list;
    }

    public void dfs(TreeNode root, int level){
        if(root == null) return;
        if(!map.containsKey(level)){
            list.add(root.val);
            map.put(level, root.val);
        }
        if(root.right != null){
            dfs(root.right, level+1);
        }
        if(root.left != null){
            dfs(root.left, level+1);
        }
        return;
    }
}
```