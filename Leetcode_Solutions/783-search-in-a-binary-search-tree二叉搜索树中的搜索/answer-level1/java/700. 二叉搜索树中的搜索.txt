/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/8
 *
 * 解题思路: 常规题目
 *
 */
```
public class leetcode700 {

    TreeNode res = null;
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null) res =  null;
        else if(root.val == val) res =  root;
        else if(root.val > val) searchBST(root.left,val);
        else if(root.val < val) searchBST(root.right,val);

        return res;
    }

    public TreeNode searchBST2(TreeNode root, int val) {
        if(root == null) return null;
        else if(root.val == val) return root;
        else if(root.val > val) return searchBST(root.left,val);
        else return searchBST(root.right,val);
    }

    public TreeNode searchBST3(TreeNode root, int val) {
        if(root == null) return null;

        if(root.val == val) return root;

        if(root.val > val) return searchBST(root.left,val);

        return searchBST(root.right,val);
    }

    public TreeNode searchBST4(TreeNode root, int val) {
        if(root == null){
            return null;
        }
        TreeNode res = null;
        if(root.val == val) res =  root;
        else if(root.val > val)  res =  searchBST(root.left,val);
        else res = searchBST(root.right,val);

        return res;
    }

    public static void main(String[] args) {

    }
}
```