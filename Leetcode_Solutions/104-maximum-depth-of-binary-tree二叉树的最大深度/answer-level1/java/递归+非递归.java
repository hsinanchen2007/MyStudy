```
class Solution {
    /**
     * 非递归版本
     * 可以使用DFS实现，需要用到辅助栈
     */
    public  int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Stack<Record> stack=new Stack<Record>();//辅助栈
        stack.add(new Record(root,1));
        HashSet<TreeNode> set=new HashSet<TreeNode>();//用于判断节点是否已经访问过
        set.add(root);
        int depth=1;
        while(!stack.empty()){
            Record Cur=stack.peek();//获取当前栈顶的节点
            depth=Math.max(depth,Cur.level);//查看当前栈顶节点的深度是否比记录的深度要深(因为上一轮循环中可能会向栈中添加入新的下层节点)
            //若当前栈顶节点的左子节点不为空，并且之前没有访问过，则将该左子节点压入栈中，并且标记为访问过的节点，并跳过本次循环
            if(Cur.node.left!=null && !set.contains(Cur.node.left)){
                stack.add(new Record(Cur.node.left,Cur.level+1));
                set.add(Cur.node.left);
                continue;
            }
            //若当前栈顶节点的右子节点不为空，并且之前没有访问过，则将该右子节点压入栈中，并且标记为访问过的节点，并跳过本次循环。
            if(Cur.node.right!=null && !set.contains(Cur.node.right)){
                stack.add(new Record(Cur.node.right,Cur.level+1));
                set.add(Cur.node.right);
                continue;
            }
            //只有当前栈顶节点的左右子节点都为空或者都访问过后，则将该栈顶的节点弹出。
            stack.pop();
        }
        return depth;
    }
    class Record{
        TreeNode node;
        int level;

        public Record(TreeNode node ,int level){
             this.node=node;
             this.level=level;
        }
    }
}
```
```
    /**
     * 递归版本
     */
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        int leftDepth = maxDepth_1(root.left);
        int rigthDepth = maxDepth_1(root.right);
        return Math.max(leftDepth, rigthDepth) + 1;
    }
```

