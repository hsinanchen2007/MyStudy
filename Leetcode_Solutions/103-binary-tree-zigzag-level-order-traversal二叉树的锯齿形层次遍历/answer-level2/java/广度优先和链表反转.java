```
class Solution {
    List<List<Integer>> levels = new ArrayList<>();
    //广度优先搜索算法
    public void helper(TreeNode root, int level){
        if(levels.size() == level){
            levels.add(new ArrayList<>());
        }
        levels.get(level).add(root.val);
        if(root.left != null)
            helper(root.left, level+1);
        if(root.right != null)
            helper(root.right, level+1);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null)
            return levels;
        helper(root,0);
        int size = levels.size();
        //偶数行链表反转
        for(int i = 0; i < size; i++){
            if(i % 2 != 0)
                Collections.reverse(levels.get(i));
        }
        return levels;
    }
}
```
