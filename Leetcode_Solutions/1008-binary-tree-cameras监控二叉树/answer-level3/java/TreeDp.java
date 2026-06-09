脑子转不动了，想不了贪心，写了个treeDp 感觉麻烦得要死
具体也是分三种状态，然后根据状态直接min
```java []
public class leetcode968 {
    public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
   class DPvalue{
        int setCamera;
        int noCamera;
        int notCover;
   }
    public int minCameraCover(TreeNode root) {
        DPvalue value = treeDp(root);
        return Math.min(value.setCamera, value.noCamera);
    }

    private DPvalue treeDp(TreeNode root){
        if ((root.left == null) && (root.right ==null)){
            DPvalue value = new DPvalue();
            value.noCamera = 1;
            value.setCamera = 1;
            value.notCover = 0;
            return value;
        }
        DPvalue leftValue = null;
        DPvalue rightValue = null;
        if (root.left!=null){
            leftValue = treeDp(root.left);
        }
        if (root.right !=null){
            rightValue = treeDp(root.right);
        }
        if ((leftValue == null) || (rightValue == null)){
            DPvalue childValue = leftValue ==null? rightValue:leftValue;
            DPvalue value = new DPvalue();
            value.setCamera = Math.min(Math.min(childValue.setCamera,childValue.noCamera),childValue.notCover)+1;
            value.noCamera = childValue.setCamera;
            value.notCover = childValue.noCamera;
            value.noCamera = Math.min(value.setCamera, value.noCamera);
            return value;
        } else {
            int leftMin =  Math.min(Math.min(leftValue.setCamera,leftValue.noCamera),leftValue.notCover);
            int rightMin =  Math.min(Math.min(rightValue.setCamera,rightValue.noCamera),rightValue.notCover);
            DPvalue value = new DPvalue();
            value.setCamera = leftMin+rightMin+1;
            value.notCover = leftValue.noCamera + rightValue.noCamera;
            value.noCamera = Math.min(leftValue.noCamera+rightValue.setCamera, leftValue.setCamera+rightValue.noCamera);
            value.noCamera = Math.min(value.setCamera, value.noCamera);
            return value;
        }
    }
}
```
