// 1.前序遍历获取深度,将每一层的左元素加入,根据深度逐层添加右元素
```
class Solution {
    private List<List<Integer>> list = new ArrayList();
    public List<List<Integer>> levelOrder(TreeNode root) {
        //  当前层级列表
        levelOrderList(0,root);
        return list;
    }

    private void levelOrderList(int leve,TreeNode root){
        if(root == null) return;
        // 创建层级对应集合
        if(list.size()== leve) list.add(new ArrayList<Integer>());
        // 将当前层级节点加入集合
        list.get(leve).add(root.val);
        // 递归子节点
        levelOrderList(leve + 1, root.left);
        levelOrderList(leve + 1, root.right);
    }
}
```
