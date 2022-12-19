```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    Map<Integer,List<Integer>>map;
    public List<List<Integer>> findLeaves(TreeNode root) {
    List<List<Integer>>list=new ArrayList<>();
        if(root==null)
            return list;
        map=new HashMap<>();
        preorder(root);
        for(int i:map.keySet())
        {
            list.add(map.get(i));
        }
        return list;
    }
    public int preorder (TreeNode root){
        //每一个结点都要从0开始算他的深度。
        int position=0;
        if(root.left!=null)
        {
            position=preorder(root.left)+1;
        }
        if(root.right!=null)
        {
            position=Math.max(position,preorder(root.right)+1);
        }
        if(!map.containsKey(position))
        {
            List<Integer>list=new ArrayList<>();
            list.add(root.val);
        map.put(position,list);
        }
        else{
            List<Integer>list=map.get(position);
            list.add(root.val);
            map.put(position,list);
        }
        return position;
    }
}
```