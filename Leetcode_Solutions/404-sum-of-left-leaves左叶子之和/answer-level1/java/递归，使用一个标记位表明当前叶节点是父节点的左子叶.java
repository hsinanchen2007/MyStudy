class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        return help(root, false);       
    }
    
    private int help(TreeNode root, boolean isLeftChild){             //使用一个标志位表明该节点是父节点的左孩子还是右孩子
        int result = 0;
        if (null == root){
            return result;
        }
        if (null == root.left && null == root.right && isLeftChild){  //左孩子、右孩子都为null表示根节点，标志位true表示是左子叶
            result += root.val;
        }
        
        return result + help(root.left, true) + help(root.right,false);
    }
}