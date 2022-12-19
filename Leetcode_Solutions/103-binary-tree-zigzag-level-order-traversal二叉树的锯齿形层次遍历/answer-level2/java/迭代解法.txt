### 解题思路
在题目102的基础上，添加头插和尾插的逻辑。

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if(root == null){
            return results;
        }
        boolean left2Right = true;
        ArrayDeque<TreeNode> elements = new ArrayDeque<TreeNode>();
        elements.addLast(root);
        while(!elements.isEmpty()){
            LinkedList<Integer> r = new LinkedList<>();
            for(int i = elements.size(); i > 0; i--){
                TreeNode treeNode = elements.removeFirst();
                if(treeNode.left != null){
                    elements.addLast(treeNode.left);
                }
                if(treeNode.right != null){
                    elements.addLast(treeNode.right);
                }
                //如果是从左到右，使用尾插法，否则使用头插法
                if(left2Right){
                    r.addLast(treeNode.val);
                } else {
                    r.addFirst(treeNode.val);
                }
            }
            results.add(r);
            left2Right = !left2Right;
        }
        return results;
    }
}
```