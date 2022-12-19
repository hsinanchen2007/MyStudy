### 解题思路

深度优先搜索遍历
返回一个数组[最大数,最小数，0或者1(表示是否是二叉搜索树)]
数组用来记录所有自己和所有子树的最数最小数
检查右子树最小数是否比自己大
检查左子树最大数是否比自己小

### 代码
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root==null)
        return true;
        int temp[] = check(root);
        if(temp[2]==1)
        return true;
        else
        return false;
    }

    public int[] check(TreeNode root){
        int[] left = null,right = null;
        int[] result = null;
        if(root.left!=null){
            left = check(root.left);
        }
        if(root.right!=null){
            right = check(root.right);
        }
        if(left==null&&right==null){
            return new int[]{root.val,root.val,1};
        }
        if(left!=null){
            if(left[0]>=root.val||left[2]==0){
                return new int[]{root.val,root.val,0};
            }
            if(right==null){
                result = left;
                result[0] = root.val;
            }
        }
        if(right!=null){
            if(right[1]<=root.val||right[2]==0){
                return new int[]{root.val,root.val,0};
            }
            if(left==null){
                result = right;
                result[1] = root.val;
            }
        }
        if(left!=null&&right!=null){
            result = new int[3];
            result[0] = Math.max(left[0],right[0]);
            result[1] = Math.min(left[1],right[1]);
            result[2] = left[2]&right[2];
        }
        return result;
    }
}
```