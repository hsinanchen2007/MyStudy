虽然效率不高，但很简洁易懂，随便吐槽下Java的基本类库用的太恼火了，远不如Python一半。
```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
      List<Integer> pre = new ArrayList();
      List<Integer> in = new ArrayList();
      for(int i=0;i<preorder.length;i++){
        pre.add(preorder[i]);
        in.add(inorder[i]);
      }
      return helper(pre,in);
    }

    private TreeNode helper(List pre,List in){
      if(in.size()==0) return null;
      TreeNode root = new TreeNode((int)pre.get(0));
      int i = in.indexOf(pre.get(0));
      root.left = helper(pre.subList(1,i+1),in.subList(0,i));
      root.right = helper(pre.subList(i+1,pre.size()),in.subList(i+1,in.size()));
      return root;
    }
}
```
