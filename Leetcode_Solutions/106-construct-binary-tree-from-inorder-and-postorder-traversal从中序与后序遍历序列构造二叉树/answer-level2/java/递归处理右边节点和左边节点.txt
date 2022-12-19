执行结果：
通过
显示详情
执行用时 :
7 ms
, 在所有 Java 提交中击败了
89.32%
的用户
内存消耗 :
39.5 MB
, 在所有 Java 提交中击败了
38.56%
的用户
```
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
    Map<Integer,Integer> map = new HashMap<>();
    int pos;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int len = inorder.length;
        if(len==0)return null;
        pos = len-1;
        for(int i=0; i<len; i++){
            map.put(inorder[i],i);
        }
        return get(postorder,inorder,0,len-1);
        
    }
    private TreeNode get(int[] postorder, int[] inorder, int is,int ie){
        if(is>ie)return null;
        if(is==ie){
            pos--;
            return new TreeNode(inorder[is]);
        }
        int cur = postorder[pos--];
        TreeNode tn = new TreeNode(cur);
        int mid = map.get(cur);
        if(mid<ie){tn.right= get(postorder,inorder,mid+1,ie);}
        if(mid>is){tn.left = get(postorder,inorder,is,mid-1);}
        
        return tn;
        
    }
}
```
