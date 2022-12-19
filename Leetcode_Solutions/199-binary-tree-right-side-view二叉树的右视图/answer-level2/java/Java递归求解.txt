耗时1ms，只要保存每层最右边的节点值就行，因此遍历顺序是`根-右-左`，对于当前深度，只保存第一个遍历到的节点
```
class Solution {
    List<Integer> result = new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
        traverse(root,1);
        return result;
    }
    public void traverse(TreeNode root, int depth){
        if(root==null) return ;
        if(result.size()<depth){
            result.add(root.val);
        }
        traverse(root.right,depth+1);
        traverse(root.left,depth+1);
    }
}
```