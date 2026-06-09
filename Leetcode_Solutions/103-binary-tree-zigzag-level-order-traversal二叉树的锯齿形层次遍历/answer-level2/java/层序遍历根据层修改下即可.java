层序遍历怎么来，这题还是怎么来，但是需要增加一个跟层有关的参数，此处用layer,0表示从左往右的层,1表示从右往左的层，具体看代码
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null)return ans;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        int layer=0;
        while(!queue.isEmpty()){
            List<Integer> res=new ArrayList<>();
            int len=queue.size();
            for(int i=0;i<len;i++){
                TreeNode tmp=queue.poll();
                if(layer==0){           //从左往右层，在res末端添加即可
                    res.add(tmp.val);
                }else{                  //从右往左层，在res首端添加即可
                    res.add(0,tmp.val);
                }
                if(tmp.left!=null)queue.offer(tmp.left);
                if(tmp.right!=null)queue.offer(tmp.right);
                }
                ans.add(res);
                layer=1-layer;          //层更新   
            }
            return ans;

    }
}