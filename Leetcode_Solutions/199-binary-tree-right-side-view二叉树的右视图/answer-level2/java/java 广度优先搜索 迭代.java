/*思想就是层次遍历
将每一行的最后一个元素加入列表中*/
class Solution {
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    List<Integer> list = new LinkedList<>();
    public List<Integer> rightSideView(TreeNode root) {
        if(root==null)
        {
            return list;
        }
        queue.add(root);
        while(!queue.isEmpty())
        {
            int count = queue.size();
            for(int i = 1;i<=count;i++)
            {
                TreeNode node = queue.poll();
                if(node.left!=null) queue.add(node.left);
                if(node.right!=null) queue.add(node.right);
                if(i==count)
                {
                    list.add(node.val);
                }
            }
        }
        return list;
    }
}