```
class Solution {
    public void flatten(TreeNode root) {
        while(root != null){
            TreeNode cur = root.left;
            if(cur == null){
                root = root.right;
                continue;
            }
            while(cur.right != null){
                cur = cur.right;
            }
            cur.right = root.right;         
            root.right = root.left;
            root.left = null;
            root = root.right;
            
        }
    }
}
![LeetCode114.jpg](https://pic.leetcode-cn.com/9af8e854719a695262392de1547f11df171206e3a28290108826fc9605220c25-LeetCode114.jpg)
```
