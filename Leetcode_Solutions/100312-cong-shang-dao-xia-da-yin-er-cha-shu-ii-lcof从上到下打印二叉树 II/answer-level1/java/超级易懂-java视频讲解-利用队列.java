class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null)     return res;

        //两种数据结构: Queue +  ArrayList
        Queue<TreeNode> queue = new LinkedList<>();
        ArrayList<Integer> list = new ArrayList<>();

        //核心方案: queue中取出一个元素, 再把其左右孩子加入queue
        queue.add(root);

        while(!queue.isEmpty()){
            ArrayList<Integer> temp = new ArrayList<>();
            int size = queue.size(); //一定要先获得, 防止fast fail

            for(int i = 0; i < size; i++){
                TreeNode node = queue.remove(); //queue中取出一个节点

                temp.add(node.val); //把节点值加入list
                if(node.left != null)   queue.add(node.left); //左孩子不空, 加入queue
                if(node.right != null)  queue.add(node.right);
            }
            res.add(temp);
        }

        return res;
    }
}

务必配合一下视频链接:
https://www.bilibili.com/video/BV1vQ4y1M7wv/