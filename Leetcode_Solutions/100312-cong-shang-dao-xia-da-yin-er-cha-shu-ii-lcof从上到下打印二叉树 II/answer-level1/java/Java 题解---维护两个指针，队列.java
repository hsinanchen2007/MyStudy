利用到二叉树的层序遍历。
层序遍历打印的同时，维护两个变量 cur（当前层的数量）、next（下一层的数量）。
每次队列 poll 出一个节点时，cur 减一，如果该结点存在孩子节点，则 next 加上孩子节点的数量（下一层的数量）。当 cur == 0 时，即当前层数的节点打印完，开始下一层的打印 cur = next。


class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> result = new ArrayList();
        Queue<TreeNode> queue = new LinkedList<>();
        ArrayList<Integer> line = new ArrayList<>();
        int cur = 0, next = 0; // 当前层的数量，下一层的数量
        if(root != null)
            queue.offer(root);
        cur = 1;
        while(queue.size() != 0){
            TreeNode node = queue.poll();
            line.add(node.val);

            if(node.left != null){
                queue.offer(node.left);
                next ++;
            }
            if(node.right != null){
                queue.offer(node.right);
                next ++;
            }  
           // 当前层数打印完，开始打印下一层。
            if(--cur == 0){
                result.add(line);
                line = new ArrayList<>();
                cur = next;
                next = 0;
            }

       }
        if(line.size() != 0)
            result.add(line);
    
        return result;
    }
}