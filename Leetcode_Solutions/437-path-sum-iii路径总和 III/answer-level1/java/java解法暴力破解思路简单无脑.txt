```
    //定义全局变量来存储结果数量
    int result = 0;
    //新建集合储存所有节点
    List<TreeNode> nodeList = new ArrayList<>();
    
    public int pathSum(TreeNode root, int sum) {
        nodeList(root);
        //循环去将每个节点都当成一个头结点来处理 因为不会回溯哈哈哈
        for (TreeNode node:nodeList) {
            pathSum(node,sum,0);
        }
        return result;
    }
    //递归将所有节点放到集合中
    private void nodeList(TreeNode root){
        if(root == null){
            return;
        }
        nodeList.add(root);
        nodeList(root.left);
        nodeList(root.right);
    }
    //递归计算从当前节点往下的所有路径和
    private void pathSum(TreeNode root,int sum,int tempSum){
        if(root == null){
            return ;
        }
        tempSum = tempSum + root.val;
        if(tempSum == sum){
            result++;
        }
        pathSum(root.left,sum,tempSum);
        pathSum(root.right,sum,tempSum);
    }
```
执行结果：
通过
显示详情
执行用时 :23 ms, 在所有 java 提交中击败了11.76%的用户
内存消耗 :39.3 MB, 在所有 java 提交中击败了67.21%的用户