思路如下：选择层次遍历二叉树，当进入树中新的一层的时候，建立一个链表，用来放置二叉树中本层的所有节点元素，最后一次读取每个链表的最后一个元素即可求解。
```
class Solution {
    List<List<Integer>>output=new ArrayList<List<Integer>>();
    public List<Integer> rightSideView(TreeNode root) {
        levels(root,0);
        int i;
        List<Integer>ans=new ArrayList<Integer>();
        //获取每个链表的最后一个元素即可。
        for(i=0;i<output.size();i++){
            List<Integer>s=output.get(i);
            ans.add(s.get(s.size()-1));
        }
        return ans;
    }
    //层次遍历数组，为每一层的节点建立一个链表
    public void levels(TreeNode root,int level){
        if(root==null) return;
        if(output.size()==level){
            output.add(new ArrayList<Integer>());
        }
        output.get(level).add(root.val);
        levels(root.left,level+1);
        levels(root.right,level+1);
        
    }
}
```
