```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if(root == null){
            return ans;
        }
        Deque<TreeNode> queue = new LinkedList<>();
        queue.offerLast(root);
        while(queue.size() > 0){
            int size = queue.size();
            List<Integer> list = new LinkedList<>();
            while(size > 0){
                TreeNode node = queue.pollFirst();
                if(node.left != null){
                    queue.offerLast(node.left);
                }
                if(node.right != null){
                    queue.offerLast(node.right);
                }
                list.add(node.val);
                size--;
            }
            ans.add(list);
        }
        return ans;
    }
}
```