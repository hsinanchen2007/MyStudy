### 解题思路
DFS

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
    class  Pair{
        public TreeNode treeNode;
        public Integer integer;
        public Pair(TreeNode treeNode,Integer integer){
            this.treeNode=treeNode;
            this.integer=integer;
        }
    }
    public int maxDepth(TreeNode root) {
        LinkedList<Pair> stack = new LinkedList<>();
        if(root!=null){
            stack.add(new Pair(root,1));
        }
        int maxdepth=0;
        while (!stack.isEmpty()){
            Pair pair = stack.pollLast();
            TreeNode treeNode = pair.treeNode;
            int depth = pair.integer;
            maxdepth = Math.max(maxdepth,depth);
            if(treeNode.right!=null){
                stack.add(new Pair(treeNode.right,depth+1));
            }
            if(treeNode.left!=null){
                stack.add(new Pair(treeNode.left,depth+1));
            }
        }
        return maxdepth;
    }
}
```