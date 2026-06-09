class Solution {
    public int kthLargest(TreeNode root, int k) {
        List<Integer> list = inorder(root, new ArrayList<>() );
        return list.get( list.size() - k);
    }

    public List<Integer> inorder(TreeNode root, List<Integer> list){
        if(root == null)    return  list;

        //递归开始, 递归左子树
        inorder(root.left, list);
        //处理根节点, 加入list
        list.add(root.val);
        //递归右子树
        inorder(root.right, list);

        return list;
    }
}


代码详细讲解视频:
https://www.bilibili.com/video/BV1GQ4y1M72Q/