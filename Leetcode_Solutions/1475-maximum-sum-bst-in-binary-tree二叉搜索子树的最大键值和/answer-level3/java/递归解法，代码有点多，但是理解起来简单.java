```
class Solution {
    
    int ans = 0;
    
    private int[] maxSumBST2(TreeNode root) {
        int[] res = new int[2];
        if (root.left == null && root.right == null) {
            res[1] = root.val;
            ans = Math.max(ans, res[1]);
            return res;
        } else if (root.left != null && root.right == null) {
            int[] res2 = maxSumBST2(root.left);
            res[0] = res2[0];
            res[1] = res2[1];
            
            if (res[0] == 1) {
                return res;    
            }
    
            if (root.left.val < root.val) {
                res[1] += root.val;
            } else {
                res[0] = 1;
            }
            ans = Math.max(ans, res[1]);
            return res;
        } else if (root.right != null && root.left == null) {
            int[] res2 = maxSumBST2(root.right);
            res[0] = res2[0];
            res[1] = res2[1];
            
            if (res[0] == 1) {
                return res;
            }
            
            if (root.right.val > root.val) {
                res[1] += root.val;
            } else {
                res[0] = 1;
            }
            ans = Math.max(ans, res[1]);
            return res;
        } else {
            int[] res2 = new int[2];
            int[] left = maxSumBST2(root.left);
            int[] right = maxSumBST2(root.right);
            
            if (left[0] == 0 && right[0] == 0) {
                if (root.left.val < root.val && root.right.val > root.val) {
                    res2[0] = 0;
                    res2[1] = root.val + left[1] + right[1];
                } else {
                    res2[0] = 1;
                    res2[1] = Math.max(left[1], right[1]);
                }
                
            } else {
                res2[0] = 1;
                res2[1] = Math.max(left[1], right[1]);
            }
            ans = Math.max(ans, res2[1]);
            return res2;
        }

    }
    
    public int maxSumBST(TreeNode root) {
        int[] res = maxSumBST2(root);
        return ans;
    }
}
```
