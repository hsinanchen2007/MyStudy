### 解题思路
一看就懂的简易解法；

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder==null || preorder.length==0){
            return null;
        }
        Map<Integer,Integer> map = new HashMap<>();
        int inlength = inorder.length;
        for(int i=0;i<inlength;i++){
            map.put(inorder[i],i);
        }
        return solution(preorder,0,preorder.length-1,inorder,0,inlength,map);
    }
    public static TreeNode solution(int[] preorder,int s1,int e1, int[] inorder,int s2,int e2,Map<Integer,Integer> map){
        if(e1<s1||e2<s2)
            return null;
        TreeNode node = new TreeNode(preorder[s1]);
        int index = map.get(preorder[s1]);
        node.left = solution(preorder,s1+1,s1+index-s2,inorder,s2,index-1,map);
        node.right = solution(preorder,s1+index-s2+1,e1,inorder,index+1,e2,map);
        return node;
    }
}
```