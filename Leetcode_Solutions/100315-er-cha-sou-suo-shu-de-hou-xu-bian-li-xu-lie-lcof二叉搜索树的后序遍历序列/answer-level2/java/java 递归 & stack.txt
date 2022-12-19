```递归 []
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return tree(postorder,0,postorder.length-1);
    }

    boolean tree(int[] postorder, int i, int j){
        if(i>=j) return true;
        int root = postorder[j];
        int x=i;
        for(; x<j; x++){
            if(postorder[x] > root) break;
        }
        for(int n =x; n<j;n++){
            if(postorder[n] <root) return false;
        }
        return tree(postorder,i,x-1) && tree(postorder,x,j-1);
    }
}
```
```stack []
print('Hello world!')
```
