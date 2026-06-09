# 递归实现
```java []
class Solution {
    List<List<Integer>> res = new LinkedList();
    public void dfs(TreeNode root, Stack<Integer> path, int sum){
        path.push(root.val);
        if(sum-root.val==0 && root.left==null && root.right==null){
            res.add(new ArrayList(path));
        }
        else{
            if(root.left!=null) dfs(root.left,path,sum-root.val);
            if(root.right!=null) dfs(root.right,path,sum-root.val);
        }
        path.pop();
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null) return res;
        Stack<Integer> path = new Stack();
        dfs(root,path,sum);
        return res;
    }
}
```

# 迭代法
实质上是用堆栈模拟了递归过程
```java []
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new LinkedList();
        if(root==null) return res;
        Stack<LinkedList<Integer>> paths = new Stack();
        Stack<Integer> sums = new Stack();
        Stack<TreeNode> st = new Stack();
        TreeNode p=root;st.push(p);
        LinkedList<Integer> path = new LinkedList();
        path.add(root.val);
        paths.push(path);
        sums.push(sum-root.val);
        int s;
        while(st.isEmpty()==false){
            p=st.pop();
            s=sums.pop();
            path=paths.pop();
            if(s==0 && p.left==null && p.right==null) res.add(new LinkedList(path));
            else{
                if(p.left!=null){
                    LinkedList<Integer> pl=new LinkedList(path);
                    pl.add(p.left.val);
                    paths.push(pl); sums.push(s-p.left.val);st.push(p.left);
                }
                if(p.right!=null){
                    LinkedList<Integer> pr=new LinkedList(path);
                    pr.add(p.right.val);
                    paths.push(pr); sums.push(s-p.right.val);st.push(p.right);
                }
            }
        }
        return res;
    }
}
```


