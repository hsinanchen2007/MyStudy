### 解法1： 基于递归的中序遍历
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        List<Integer> list=new ArrayList<>();
        traversalBST(list,root);
        long max=-2147483649L;
        for(Integer i:list){
            if(i>max) max=i;
            else return false;
        }
        return true;
    }

    private void traversalBST(List<Integer> list,TreeNode node){
        if(node==null){
            return;
        }
        traversalBST(list,node.left);
        list.add(node.val);
        traversalBST(list,node.right);
    }
}
```


### 解法2：基于栈的中序遍历
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        Stack<TreeNode> stack=new Stack<>();
        long max=-2147483649L;
        TreeNode node=root;
        while(node!=null || !stack.isEmpty()){
            while(node!=null){
                stack.push(node);
                node=node.left;
            }
            node=stack.pop();
            if(node.val>max) {
                max=node.val;
                node=node.right;
            }
            else{
                return false;
            }
        }
        return true;
    }
}
```
