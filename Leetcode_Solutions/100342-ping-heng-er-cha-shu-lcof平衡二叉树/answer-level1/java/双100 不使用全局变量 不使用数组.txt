### 解题思路
理论上深度是正数, 使用-1做标志数, 遇见-1直接结束

### 代码

```java
class Solution {
    public boolean isBalanced(TreeNode root) {
        return depth(root)!=-1;
    }
    
    public int depth(TreeNode root){
        if(root==null)return 0;

        if(root.left==null&&root.right==null) return 1;

        int left = depth(root.left);
        int right = depth(root.right);
        
        if(left==-1||right==-1) return -1;

        if(Math.abs(left-right)<2) return Math.max(left,right)+1;
        else return -1;
    }
}
```