### 解题思路
层序遍历+反转
### 代码

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
    List<List<Integer>> list=new ArrayList();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root==null) return list;
        Deque<TreeNode> deq=new ArrayDeque();
        deq.offer(root);
        int level=1;
        while(!deq.isEmpty()){
            List<Integer> res=new ArrayList();
            int size=deq.size();
            if(level%2==1)  list.add(rightSearch(deq,size,level,res));
            else {
                Collections.reverse(rightSearch(deq,size,level,res));
                list.add(res);
            }
            level++;
        }
        return list;
    }
    // public List<List<Integer>> leftSearch(Deque<TreeNode> deq,int size,int level,List<Integer> res){
    //     for(int i=0;i<size;i++){
    //         TreeNode t=deq.pop();
    //         res.add(t.val);
    //         if(t.left!=null) deq.offer(t.left);            
    //         if(t.right!=null) deq.offer(t.right);
    //     }
    //     Collections.reverse(res);
    //     list.add(res);
    //     return list;    
    // }
    public List<Integer> rightSearch(Deque<TreeNode> deq,int size,int level,List<Integer> res){
        for(int i=0;i<size;i++){
            TreeNode t=deq.pop();
            res.add(t.val);
            if(t.left!=null) deq.offer(t.left);            
            if(t.right!=null) deq.offer(t.right);
        }    
        return res;
    }
}
```