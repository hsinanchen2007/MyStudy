```
class Solution {
    
    int pVal;
    
    int qVal;
    
    TreeNode pp = null;
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        pVal = p.val;
        qVal = q.val;
        // 判断其中一个节点是否为祖先节点
        if(test(p, q.val)){
            return p;
        }
        if(test(q, p.val)){
            return q;
        }
        traverse(root);
        return pp;
        
    }
    
    void traverse(TreeNode node){
        if(node == null || this.pp != null){
            return;
        }
        traverse(node.left);
        traverse(node.right);
        if(this.pp == null && test(node, pVal) && test(node, qVal)){
            this.pp = node;
            return;
        }
    }
    
    boolean test(TreeNode p, int val){
        if(p == null){
            return false;
        }
        if(p.val == val){
           return true ;
        }
        if(test(p.left, val) || test(p.right, val)){
            return true;
        }
        return false;
    }
}
```
