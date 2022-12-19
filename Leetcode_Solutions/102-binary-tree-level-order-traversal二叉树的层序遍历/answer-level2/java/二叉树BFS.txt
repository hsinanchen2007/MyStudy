## 循环迭代
队列思想：用队列保存遍历的路径
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            List<Integer> list = new LinkedList<>();
            Queue<TreeNode> level = new LinkedList<>();
            while(!queue.isEmpty()){
                     TreeNode node = queue.poll();
                    if(node==null) continue;
                    list.add(node.val);    
                    level.add(node.left);
                    level.add(node.right);
            }
            if(list.size()==0) return result;
            result.add(list);
            queue.addAll(level);
        }
        return result;
    }
}
```