```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 // 根据题解写的二分查找，学习了
class Solution {
    public int countNodes(TreeNode root) {
        if(root==null) return 0;
        int depth = getDepth(root);
        if(depth==0) return 1;
        int countNode = (int)Math.pow(2,depth) - 1;
        int lastnodes = (int)Math.pow(2,depth);
        int left = 1, right = lastnodes;
        int lastNum = 0;
        while(left<=right) {
            int privot = left + (right - left)/2;
             if(isExist(privot,depth,lastnodes,root)) {
                lastNum = privot;
                left = privot + 1;
            }else {
                right = privot - 1;
            }
        }
        return countNode + lastNum;
    }

    public boolean isExist(int privot,int depth,int lastnode,TreeNode root) {
        int left = 1,right = lastnode;
        for(int i=0;i<depth;i++) {
            int mid = left + (right - left)/2;
            if(privot <= mid) {
                root = root.left;
                right = mid;
            }else {
                root = root.right;
                left = mid + 1;
            }
        }
        if(root==null) return false;
        return true;
    }

    public int getDepth(TreeNode root) {
        int dep = -1;
        TreeNode node = root;
        while(node!=null) {
            dep++;
            node = node.left;
        }
        return dep;
    }

}
```
