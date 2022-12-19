class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // 分别对树先序序列化得到字符串
        String s1 = serialByPre(p);
        String s2 = serialByPre(q);
        // 比较两个字符串
        return s1.equals(s2);
    }
    public String serialByPre(TreeNode head){
        if(head == null){
            return "#_";
        }
        String res = head.val + "_";
        res += serialByPre(head.left);
        res += serialByPre(head.right);
        return res;
    }
}