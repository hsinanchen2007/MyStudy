### 解题思路
注意如果直接res.add(list),之后对list修改会同时修改已经插入到res中的list。

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
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null)    return res;
        dfs(root,sum);
        return res;
    }

    private void dfs(TreeNode node, int target){
        if(node == null)    return;
        list.add(node.val);
        target -= node.val;
        if(target == 0 && node.left == null && node.right == null){
            res.add(new ArrayList<>(list)); //注意浅拷贝
        }
        dfs(node.left,target);
        dfs(node.right,target);
        list.remove(list.size() - 1);
    }
}
```