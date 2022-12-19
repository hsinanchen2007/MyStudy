
    序号标记各节点，左节点为奇数，右节点皆为偶数, 求解所有左节点和就转化为求所有奇数节点之和。


```
    3                  0
   / \                / \
  9  20              1   2
    /  \                 /\
   15   7               3  4
```


```
    int sum=0;
    public int sumOfLeftLeaves(TreeNode root) {
        dfs(root,0);
        return sum;
    }
    private void dfs(TreeNode root,int idx){
        if(root==null){
            return;
        }
        if((idx&1)!=0&&root.left==null&&root.right==null){
            sum+=root.val;
        }
        getSum(root.left,idx*2+1);
        getSum(root.right,idx*2+2);
    }
```
