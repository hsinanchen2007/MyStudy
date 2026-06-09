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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<>();
        helper(root, sum, ans, new ArrayList<Integer>());
        return ans;
    }
    public void helper(TreeNode node, int sum, List<List<Integer>> ans, List<Integer> list){
        if(node == null){
            return;
        }
        list.add(node.val);
        if(sum == node.val && node.left == null && node.right == null){
            ans.add(new ArrayList<>(list));
        }
        helper(node.left, sum - node.val, ans, list);
        helper(node.right, sum - node.val, ans, list);
        list.remove(list.size() - 1);

    }
}
```