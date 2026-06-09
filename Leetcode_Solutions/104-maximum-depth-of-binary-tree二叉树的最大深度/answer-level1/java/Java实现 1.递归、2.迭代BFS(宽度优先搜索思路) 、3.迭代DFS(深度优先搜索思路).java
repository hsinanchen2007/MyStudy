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
    //递归
    public  int maxDepth(TreeNode root){
        if(root==null) return 0;
        int dep1 = maxDepth(root.left);
        int dep2 = maxDepth(root.right);
        return Math.max(dep1,dep2)+1;
    }
    //bfs
    public  int maxDepth1(TreeNode root){
        LinkedList<TreeNode> queue = new LinkedList();
        if(root!=null){
            queue.add(root);
        }
        int depth=0;
        while(!queue.isEmpty()){
            int len = queue.size();
            depth++;
            for(int i=0;i<len;i++){
                TreeNode cur = queue.pollFirst();
                if(cur.left!=null){
                    queue.add(cur.left);
                }
                if(cur.right!=null){
                    queue.add(cur.right);
                }
            }
        }
        return depth;
    }
    class  Pair{
        public TreeNode treeNode;
        public Integer integer;
        public Pair(TreeNode treeNode,Integer integer){
            this.treeNode=treeNode;
            this.integer=integer;
        }
    }
    //dfs 前序遍历
    public int maxDepth2(TreeNode root){
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