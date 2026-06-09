***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，持续更新。***

使用递归和迭代两种方法：


```
class Solution{
//中序遍历：左->中->右，递归法：
    public List<Integer> inorderTraversal1(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        helper(root,res);
        return res;
    }

    private void helper(TreeNode node,List<Integer> list){
        if(node == null) return;
        helper(node.left,list);
        list.add(node.val);
        helper(node.right,list);
    }

    //2.迭代法，使用stack来实现
    public List<Integer> inorderTraversal2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        List<Integer> list = new ArrayList<>();
        //将所有最左边元素加入stack
        TreeNode cur = root;
        while(cur != null || !stack.isEmpty()){
            if(cur != null){
                //将最左边的所有元素压栈
                stack.add(cur);
                cur = cur.left;
            }else{
                //弹栈
                cur = stack.pop();
                list.add(cur.val);
                cur = cur.right;
            }
        }
        return list;
    }
}