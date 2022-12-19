 public static int res;
    public static int sumRootToLeaf(TreeNode root) {
        if(root == null){
            return 0;
        }
        res = 0;
        dfs(root,"");
       // System.out.println(res);
        return res;
    }

    private static void dfs(TreeNode root,String string) {
        if(root != null){
            string += root.val;
            if(root.left == null && root.right == null){
                //System.out.println(string + " : " + Integer.valueOf(string,2));
                res += Integer.valueOf(string,2);
                return;
            }
            dfs(root.left,string);
            dfs(root.right,string);
        }
    }