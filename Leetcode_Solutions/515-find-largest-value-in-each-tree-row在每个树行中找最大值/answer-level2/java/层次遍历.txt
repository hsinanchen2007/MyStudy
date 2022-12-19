```
class Solution {
    List<List<Integer>>output=new ArrayList<List<Integer>>();
    public List<Integer> largestValues(TreeNode root) {
        level(root,0);
        List<Integer>ans=new ArrayList<Integer>();
        for(int i=0;i<output.size();i++){
            ans.add(output.get(i).get(0));
        }
        return ans;
    }
    public void level(TreeNode root,int level){
        if(root!=null){
        if(output.size()==level){
            List<Integer>ans=new ArrayList<Integer>();
            output.add(ans);
        }
        if(output.get(level).size()==0){
             output.get(level).add(root.val);
        }else{
            if(output.get(level).get(0)<root.val){
                output.get(level).remove(0);
                output.get(level).add(root.val);
            }
        }
        level(root.left,level+1);
        level(root.right,level+1);
        }
    }
}
```
