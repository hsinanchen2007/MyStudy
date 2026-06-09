class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if(original==null) return null;
        if(original==target) return cloned;
        TreeNode l=getTargetCopy(original.left,cloned.left,target);
        if(l!=null) return l;
        TreeNode r=getTargetCopy(original.right,cloned.right,target);      
        if(r!=null) return r;
        return null;
    }
}