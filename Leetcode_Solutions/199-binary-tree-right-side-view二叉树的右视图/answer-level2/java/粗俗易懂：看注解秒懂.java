```
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        // 思路：二叉树的层序遍历，取每层的最后一个节点的值
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        Queue<TreeNode> queue = new ArrayDeque();
        queue.add(root);
        while (!queue.isEmpty()){
            int curCount = queue.size();
            TreeNode curNode = null; // 小小优化，这里先声明，等for循环之后curNode的值也就是当前层最后一个了
            for (int i = 0; i < curCount; i++){
                curNode = queue.poll();
                if (curNode.left != null) queue.add(curNode.left);
                if (curNode.right != null) queue.add(curNode.right);
            }
            result.add(curNode.val);
            /* 第一版，在for循环里面每次都要判断，上面小优化
            for (int i = 0; i < curCount; i++){
                TreeNode curNode = queue.poll();
                if (i == curCount - 1){ // 当前层最后一个加入到结果集中
                    result.add(curNode.val);
                }
                if (curNode.left != null) queue.add(curNode.left);
                if (curNode.right != null) queue.add(curNode.right);
            }*/
        }

        return result;
    }
}
```
