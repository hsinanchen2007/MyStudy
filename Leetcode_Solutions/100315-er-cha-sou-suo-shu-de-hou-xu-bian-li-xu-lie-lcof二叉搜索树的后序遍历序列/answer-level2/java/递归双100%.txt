```
class Solution {
    public  boolean verifyPostorder(int[] postorder) {
        return help(postorder);
    }

    private  boolean help(int[] postorder) {
        if (postorder==null||postorder.length <= 1) {
            return true;
        }
        int root = postorder[postorder.length - 1];
        int flag = 0;
        int index = -1;
        for (int i = 0; i < postorder.length - 1; i++) {
            if (flag == 0 && postorder[i] > root) {
                index = i;
                flag = 1;
                continue;
            }
            if (flag == 1 && postorder[i] < root) {
                return false;
            }
        }
        int[] left;
        if(index==-1){
            left=new int[postorder.length-1];
            index=postorder.length-1;
        }else{
            left= new int[index];
        }
        if (index > 0) {
            System.arraycopy(postorder, 0, left, 0, index);
        }
        int[] right = new int[postorder.length - 1 - index];
        if (index < postorder.length - 2) {
            System.arraycopy(postorder, index, right, 0, right.length);
        }
        return help(left) && help(right);
    }
}
```
