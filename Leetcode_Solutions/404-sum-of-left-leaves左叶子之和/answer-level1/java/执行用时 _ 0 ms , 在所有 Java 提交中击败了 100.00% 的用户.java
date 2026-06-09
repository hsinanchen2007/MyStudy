### 解题思路
在递归时，传递一个boolean的标志。在递归root.left，标志=true

### 代码

```java
class Solution {
    int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        inScan(root, false);
        return sum;
    }

    void inScan(TreeNode root, boolean left){
        if(root == null)
            return;

        if(root.left == null && root.right == null){
            if(left){
                sum += root.val;
            }
            return;
        } 

        inScan(root.left, true);
        inScan(root.right, false);
    }
}
```