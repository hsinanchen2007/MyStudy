/**
 * @Project
 * @Author zhaozhen
 * @Email 
 * @Date 2019/9/7
 *
 * 解题思路：深度便利 然后叶子节点判断 然后加到全局变量
 * 
 * sumOfLeftLeaves_exe(TreeNode root , int l) 中l标识位 ： 0-右支 1：左支 开始默认右支
 */

```

    int val_sum = 0;

    public int sumOfLeftLeaves(TreeNode root) {
        return sumOfLeftLeaves_exe(root,0);
    }

    public int sumOfLeftLeaves_exe(TreeNode root , int l){

        if(root == null){
            return 0;
        }

        if(l == 1 && root.left == null && root.right == null){
            val_sum += root.val;
        }

        sumOfLeftLeaves_exe(root.left , 1);
        sumOfLeftLeaves_exe(root.right , 0);

        return val_sum;
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        TreeNode d = new TreeNode(4);
        TreeNode e = new TreeNode(5);

        a.left = b;
        a.right = c;
        b.left = d;
        d.left = e;

        leetcode404 leetcode404 = new leetcode404();
        int res = leetcode404.sumOfLeftLeaves(a);

        int debug = 0;
    }

```