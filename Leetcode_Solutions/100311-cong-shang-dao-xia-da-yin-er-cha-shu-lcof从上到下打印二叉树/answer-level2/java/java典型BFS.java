### 解题思路
BFS用List存节点，每次在头部取，在尾部添加，取节点的时候顺便把val存储起来

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
    public int[] levelOrder(TreeNode root) {
        if(root == null)return new int[0];
        LinkedList<TreeNode> li = new LinkedList<>();
        li.add(root);
        List<Integer> nums = new ArrayList<>();
        while(!li.isEmpty()){
            TreeNode r = li.removeFirst();
            nums.add(r.val);
            if(r.left != null){
                li.add(r.left);
            }
            if(r.right != null){
                li.add(r.right);
            }
        }
        int[]  res = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            res[i] = nums.get(i);
        }
        // System.out.println(nums);
        return res;
    }
}
```