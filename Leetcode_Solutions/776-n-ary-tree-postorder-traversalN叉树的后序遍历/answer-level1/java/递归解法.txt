与二叉树的后序遍历类似，根节点需要在孩子节点的后续添加。

class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if(root == null) return list;
        for(int i = 0;i < root.children.size();i++)
            list.addAll(postorder(root.children.get(i)));
        list.add(root.val);
        return list;
    }
}