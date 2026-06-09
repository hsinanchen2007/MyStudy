利用二叉搜索树的性质，即中序遍历便能得到一个从小到大递增的数组，而题目又说所有数是非负的，因此可推出最小绝对差必定出现在相邻两个元素之间，而且是后减前，因此只需先使用递归得到一个list，然后再去遍历这个list即可，算法的时间复杂度是O(n)
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
    List<Integer> list = new ArrayList<>();
    public int getMinimumDifference(TreeNode root) {
        //由于是二叉搜索树，因此只需比较相邻两点的差即可
        DFS(list,root);
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < list.size() - 1; i++){
            min = Math.min(min,list.get(i + 1) - list.get(i));
        }
        return min;
    }
    public void DFS(List<Integer> list,TreeNode tn){
        if(tn != null){
            DFS(list,tn.left);
            list.add(tn.val);
            DFS(list,tn.right);
        }
    }
}