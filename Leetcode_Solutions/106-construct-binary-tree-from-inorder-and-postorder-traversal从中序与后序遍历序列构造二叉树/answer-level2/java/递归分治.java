### 解题思路
此处撰写解题思路

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
    int postorder[],inorder[];
    int p;
    HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.postorder=postorder;
        this.inorder=inorder;
        this.p=inorder.length;
        for(int i=0;i<inorder.length;i++){
            map.put(inorder[i],i);
        }
        return buildTree(0,inorder.length-1);
    }
    TreeNode buildTree(int l,int r){
        if(l>r||p<0)return null;
        p--;
        int ip=map.get((postorder[p]));
        TreeNode t=new TreeNode(postorder[p]);
        t.right=buildTree(ip+1,r);
        t.left=buildTree(l,ip-1);
        return t;
    }
}
```