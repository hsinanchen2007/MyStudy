思路就这几点 
1. DFS遍历 
2. 选择一个节点为起始点或终止点，然后计算符合条件路径的数目。
详细描述看代码吧。
```
 //找出和等于sum的路径的数量:
    // 采取后续遍历的思路：每次判断以当前节点为最后节点的路径是否存在和等于sum
    public int pathSum(TreeNode root, int sum) {
        //1.获取从根节点到叶子节点的全部路径 ：采用DFS方法
        List<Integer> path = new ArrayList<>(); //记录从root节点到叶子节点的路径
        //迭代的DFS
        Stack<TreeNode> stack = new Stack<>();
        TreeNode visited = null; //记录上一次访问的节点
        int res = 0; //计数器：计算路径的数目
        while (!stack.isEmpty() || root != null) {
            //获最左子树的位置
            while (root != null) {
                path.add(root.val);
                stack.add(root);
                root = root.left;
            }
            root = stack.peek(); //先不出栈,防止该节点存在右子树
            if (root.right != null && root.right != visited) {  //节点存在右子树
                root = root.right;
            } else {
                //当前节点为叶子节点或者其子节点已经全部访问过了
                root = stack.pop();
                //visit node(判断以该节点结尾的路径是否存在和为sum)
                res += countRightPath(path, sum);
                path.remove(path.size() - 1); //删除访问过的节点
                visited = root; //记录上一次访问节点
                root = null;  //该结点的左右子树都已出栈，所以要继续出栈，访问其父结点
            }
        }
        return res;
    }

    //注意：由于path中存在负数,因此计数器不是递增的
    private int countRightPath(List<Integer> path, int sum) {
        int res = 0;
        //从path最后一个节点开始访问
        int currentValue = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            currentValue += path.get(i);
            if (currentValue == sum)
                res++;
        }
        return res;
    }
```
