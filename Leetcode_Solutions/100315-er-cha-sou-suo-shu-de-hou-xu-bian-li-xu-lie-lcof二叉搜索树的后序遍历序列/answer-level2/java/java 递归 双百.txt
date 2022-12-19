class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder.length<2)return true;
        return go(postorder,0,postorder.length-1);
    }
    public boolean go(int[] p , int left ,int right){
        if(left>=right)return true;
        int head = p[right];
        int l = left;
        int r = right;
        r--;
        while(r>l&&p[r]>head)r--;
        while(l<r&&p[l]<head)l++;
        if(l<r)return false;
        return go(p,left,l)&&go(p,l+1,right-1);
    }
}