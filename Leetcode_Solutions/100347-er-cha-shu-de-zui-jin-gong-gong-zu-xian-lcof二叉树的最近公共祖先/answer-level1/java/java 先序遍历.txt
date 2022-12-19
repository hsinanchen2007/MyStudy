### 解题思路
找到两点的路径

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
    List<TreeNode> ppath=new ArrayList();
    List<TreeNode> qpath=new ArrayList();
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p==root||q==root) return root;
        find(root,p,q,new ArrayList<TreeNode>(),new ArrayList<TreeNode>());
        TreeNode lastpre=null;
        for(int i=0;;i++){
            if(ppath.get(i)==qpath.get(i)) lastpre=ppath.get(i);
            else break;
            if(i==ppath.size()-1||i==qpath.size()-1) break;
        }
        return lastpre;
    }

    public void find(TreeNode root,TreeNode p,TreeNode q,List<TreeNode> ppath,
        List<TreeNode> qpath){
        if(this.ppath.size()>0&&this.qpath.size()>0) return;
        ppath.add(root);
        qpath.add(root);
        if(root==p) this.ppath.addAll(ppath);
        if(root==q) this.qpath.addAll(qpath);
        if(root.left!=null) {
            find(root.left,p,q,ppath,qpath);
            if(ppath.size()>0) ppath.remove(ppath.size()-1);
            if(qpath.size()>0) qpath.remove(qpath.size()-1);
        }
        if(root.right!=null) {
            find(root.right,p,q,ppath,qpath);
            if(ppath.size()>0) ppath.remove(ppath.size()-1);
            if(qpath.size()>0) qpath.remove(qpath.size()-1);
        }
        
    }
}
```