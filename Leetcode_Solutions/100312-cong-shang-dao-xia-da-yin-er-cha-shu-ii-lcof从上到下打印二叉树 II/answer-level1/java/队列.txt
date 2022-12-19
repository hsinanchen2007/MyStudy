使用队列存储每一层的元素

在打印上一层的元素之时，将下一层的元素存储进队列之中。
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null){
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>(); 
        queue.add(root);
        while(queue.size() > 0){
            List<Integer> inList = new ArrayList<>();
            int len = queue.size();
            for(int i = 0; i < len; i++){  // 扫描队列中的元素
                TreeNode temp = queue.poll();
                // 存储当前结点的左右结点
                if(temp.left != null) 
                    queue.add(temp.left);
                if(temp.right != null) 
                    queue.add(temp.right);
                inList.add(temp.val);
            }
            result.add(inList);
        }
        return result;
    }
}
```
