class Solution {
    public int[] levelOrder(TreeNode root) {
        if(root == null)     return new int[]{};

        //两种数据结构: Queue +  ArrayList
        Queue<TreeNode> queue = new LinkedList<>();
        ArrayList<Integer> list = new ArrayList<>();

        //核心方案: queue中取出一个元素, 再把其左右孩子加入queue
        queue.add(root);

        while(!queue.isEmpty()){
            TreeNode node = queue.remove(); //queue中取出一个节点
            list.add(node.val); //把节点值加入list
            if(node.left != null)   queue.add(node.left); //左孩子不空, 加入queue
            if(node.right != null)  queue.add(node.right);
        }

        //把ArrayList类型 转换为 int[]数组
        int[] res = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }

        return res;
    }
}

务必配合视频, 链接如下: 
https://www.bilibili.com/video/BV1vQ4y1M7wv/