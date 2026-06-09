执行用时 : 3 ms, 在Cousins in Binary Tree的Java提交中击败了66.18% 的用户
内存消耗 : 34.5 MB, 在Cousins in Binary Tree的Java提交中击败了79.07% 的用户
用两个队列，节点队列和深度队列，两个标志位
```
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        if(x==y)
            return false;
        int k=0;
        int leftDepth = 0, rightDepth = 0;
        Queue<TreeNode> que = new LinkedList<>();
        Queue<Integer> dp = new LinkedList<>();
        que.offer(root);
        dp.offer(k);
        boolean left = false, right = false;
        while(!que.isEmpty()||!dp.isEmpty()){
            TreeNode tempNode = que.poll();
            int tempDepth = dp.poll()+1;
            if(tempNode.left!=null){
                que.offer(tempNode.left);
                dp.offer(tempDepth);
            }
            if(tempNode.right!=null){
                que.offer(tempNode.right);
                dp.offer(tempDepth);
            }
            if(tempNode.left!=null&&tempNode.right!=null){
                if(tempNode.left.val==x&&tempNode.right.val==y){
                    return false;
                }
                if(tempNode.left.val==y&&tempNode.right.val==x){
                    return false;
                }
            }
            if(tempNode.val==x){
                leftDepth=tempDepth-1;
                left=true;
            }
            if(tempNode.val==y){
                rightDepth=tempDepth-1;
                right=true;
            }
            if(left&&right){
                break;
            }
        }
        if(leftDepth!=rightDepth){
            return false;
        }
        return true;
    }
}
```