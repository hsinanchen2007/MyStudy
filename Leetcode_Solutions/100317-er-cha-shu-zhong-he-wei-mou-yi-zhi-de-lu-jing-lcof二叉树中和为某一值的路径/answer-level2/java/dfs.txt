### 解题思路
这题要求从根节点到叶子节点就降低了很大难度。用dfs思想，到叶子结点之后开始判断是否相等。

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
    List<List<Integer>> lists = new ArrayList<>();

    public void preorder(TreeNode node, List<Integer> list, int sum){
        if(node == null){
            return;
        }
        list.add(node.val);
        if(node.left == null && node.right == null){
            int s = 0;
            for(int i = 0; i < list.size(); i++){
                s = s + list.get(i);
            }
            if(s == sum){
                this.lists.add(new ArrayList<>(list));
            }
        }
        preorder(node.left, list, sum);
        preorder(node.right, list, sum);
        list.remove(list.size()-1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null){
            return new ArrayList<>();
        }
        List<Integer> list = new ArrayList<>();
        preorder(root, list, sum);
        return this.lists;
    }
}
```