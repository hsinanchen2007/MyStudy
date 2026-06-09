最近提交结果：
通过
显示详情 
执行用时 :
2 ms
, 在所有Java提交中击败了
92.22%
的用户
内存消耗 :
34.2 MB
, 在所有Java提交中击败了
82.01%
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
    public TreeNode bstFromPreorder(int[] preorder) {
        if(preorder==null||preorder.length==0){
            return null;
        }
        
        return process(preorder, 0 , preorder.length);
    }
    private TreeNode process(int[] preorder, int start, int end){
        TreeNode node = new TreeNode(preorder[start]);
        int newStart = start+1;
        if(newStart==end){
            return node;
        }
       
        
        int middle=start;
       
        for(int i = newStart; i<end ; i++){
            if(preorder[i]>node.val){
                middle = i;
               // System.out.println("middle:"+middle);
                break;
            }
        }
        // System.out.println("bbb:"+(start+1)+"_"+middle);
        if(middle>newStart){
         //   System.out.println("left:"+(start+1)+"_"+middle);
            node.left = process(preorder, newStart , middle);
        }else if(middle==start){
        //    System.out.println("left:"+(start+1)+"_"+middle);
            node.left = process(preorder, newStart , end);
        }
        
        if(middle>start && end>middle){
         //    System.out.println("right:"+middle+"_"+end);
            node.right = process(preorder, middle , end);
        }
        
        return node;
        
    }
}
```