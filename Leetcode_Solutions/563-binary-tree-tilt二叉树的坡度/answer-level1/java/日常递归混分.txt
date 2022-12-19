正常递归
![Screen Shot 2019-10-17 at 7.57.28 PM.png](https://pic.leetcode-cn.com/4fa51a5d2100d1299644533396f9460f0446b9c932a926bbf3b073f12c5dbb10-Screen%20Shot%202019-10-17%20at%207.57.28%20PM.png)
```
public int findTilt(TreeNode root) {
        if(root == null){
            return 0;
        }
        int[] result = recall(root);
        return result[1];
    }
    
    public int[] recall(TreeNode node){
        int[] x = node.left==null ? new int[2] : recall(node.left);
        int[] y = node.right==null ? new int[2] : recall(node.right);
        int[] result = {x[0]+y[0]+node.val,Math.abs(x[0]-y[0])+x[1]+y[1]};
        return result;
    }
```
