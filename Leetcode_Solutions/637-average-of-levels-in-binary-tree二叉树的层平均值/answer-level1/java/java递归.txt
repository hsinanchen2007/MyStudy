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

    List<Double> res = new ArrayList<Double>();
    List<Integer> count = new ArrayList<Integer>();

    public List<Double> averageOfLevels(TreeNode root) {
        helpTree(root,0);
        for(int i=0;i<count.size();i++){
            res.set(i,res.get(i)/count.get(i));
        }
        return res;
    }

    void helpTree(TreeNode root,int level){
        if(root==null) return;
        if(level>=res.size()){
            res.add((double)0);
            count.add(0);
        }
        res.set(level,res.get(level)+(double)root.val); // 每一级的总数
        count.set(level,count.get(level)+1);  //每一级总个数
        helpTree(root.left,level+1);
        helpTree(root.right,level+1);
       
    }
}