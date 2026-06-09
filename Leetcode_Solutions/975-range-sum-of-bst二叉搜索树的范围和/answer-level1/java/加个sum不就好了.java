class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        return rangeSumBST(root,L,R,0);
    }
    public int rangeSumBST(TreeNode node,int L,int R,int sum){
        if(node == null) return sum;
        if(node.val >= L && node.val <= R){
            sum += node.val;
        }
        sum = rangeSumBST(node.left,L,R,sum);
        sum = rangeSumBST(node.right,L,R,sum);
        return sum;
        
    }
}