/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<String>> printTree(TreeNode root) {
        List<List<String>> res = new ArrayList();
        if(root == null)
            return res;
        int depth = getDepth(root);
        int length = (1<<depth)-1;
        for(int i = 0 ; i < depth ; i++){
            ArrayList<String> temp = new ArrayList();
            for(int j = 0 ; j < length;j++){
                temp.add("");
            }
            res.add(temp);
        }
        int curLevel = 1;
        helper(curLevel,length/2,1<<(depth-1-curLevel),depth,root,res);
        return res;
    }
    <!-- curlevel为当前层数，根节点记为第1层，base为本轮要填充的元素的下标，bias为偏移量，左子树则向左偏移，右子树向右偏移 -->
    public void helper(int curLevel,int base,int bias,int depth,TreeNode node,List<List<String>> res){
        if(node == null)
            return;        
        ArrayList<String> list = (ArrayList)res.get(curLevel-1);
        list.set(base,String.valueOf(node.val));
        curLevel++;
        int leftBase = base - bias;
        int rightBase = base + bias;
        bias = bias>>1;
        // bias >=0
        helper(curLevel,leftBase,bias,depth,node.left,res);
        helper(curLevel,rightBase,bias,depth,node.right,res);
    }

        public int getDepth(TreeNode root){
        if(root == null)
            return 0;
        return Math.max(getDepth(root.left),getDepth(root.right))+1;
    }
}