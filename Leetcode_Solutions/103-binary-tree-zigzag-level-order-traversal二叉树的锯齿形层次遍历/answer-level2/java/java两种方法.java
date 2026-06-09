方法1：用队列宽度搜索没一层，并用一个flag判断某一层是否需要反转。

```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean flag = true;
        while(!queue.isEmpty()){
            List<Integer> level = new ArrayList<>();
            int levelsize = queue.size();
            for(int i = 0; i < levelsize; i++){
                TreeNode node = queue.remove();
                if(node.left != null) queue.offer(node.left);
                if(node.right != null) queue.offer(node.right);
                
                if(flag) level.add(node.val); // list尾部添加
                else level.add(0, node.val); // list头部添加
            }
            flag = !flag;
            res.add(level);
        }
        return res;
    }
}
```

方法2：类似先序遍历，存结果的list一层尾插入，一层头插入。

```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root){
        List<List<Integer>> res = new ArrayList<>();
        helper(root, 0, res);
        return res;
    }
    
    private void helper(TreeNode root, int level, List<List<Integer>> res){
        if(root == null) return;
        if(level >= res.size()) res.add(new ArrayList<Integer>());
        
        if(level % 2 == 0) res.get(level).add(root.val);
        else res.get(level).add(0, root.val);
        
        helper(root.left, level+1, res);
        helper(root.right, level+1, res);
    }
}
```