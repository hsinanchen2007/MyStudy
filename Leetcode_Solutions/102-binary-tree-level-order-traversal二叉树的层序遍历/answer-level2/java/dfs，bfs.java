### 解题思路
这道题目比较通用的解法是bfs，维护一个queue，root先入队，然后开始pop，每次pop的时候将当前节点的left，right入队。通过一个循环来记录表示某一层。也可用dfs的方法，通过参数的形式来传递level的信息，每次深入下一层的时候level+1。

### dfs

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
    public void dfs(TreeNode node,List<List<Integer>> res,int level){
        if(node==null) return;
        if(res.size()==level){
            res.add(new ArrayList<Integer>());
        }
        res.get(level).add(node.val);
        if(node.left!=null){
            dfs(node.left,res,level+1);
        }
        if(node.right!=null){
            dfs(node.right,res,level+1);
        }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(root,res,0);
        return res;
    }
}
```

### bfs

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null){
            return new ArrayList<>();
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<List<Integer>> r = new ArrayList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            int count = queue.size();
            List<Integer> levelList = new ArrayList<>();
            while(count>0){
                TreeNode node = queue.poll();
                levelList.add(node.val);
                if(node.left!=null){
                    queue.offer(node.left);
                }
                if(node.right!=null){
                    queue.offer(node.right);
                }
                count--;
            }
            r.add(levelList);
        }
        return r;
    }
}

```