## 循环迭代
树+队列思想：队列记录遍历路径
```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>>  result= new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            List<Integer> list = new LinkedList<>();
            Queue<TreeNode> temp = new LinkedList<>();
            while(!queue.isEmpty()){
                TreeNode node = queue.poll();
                if(node==null) continue;
                list.add(node.val);
                temp.add(node.left);
                temp.add(node.right);
            }
            if(list.size()>0) result.add(0,list);
            queue.addAll(temp);
        }
        return result;
    }
}
```