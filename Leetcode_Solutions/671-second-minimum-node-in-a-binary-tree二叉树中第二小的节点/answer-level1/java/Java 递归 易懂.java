![image.png](https://pic.leetcode-cn.com/cbb7f86ce86de00ebd1c1291da4483255053dab58ca1cd81545319519db31327-image.png)

通过题目可知树中最小的值是根节点的值
在遍历树的每个节点时，与树的根节点的值进行比较，如果不等于，则和min进行比较，并把标志flag更新。
通过flag是否更改，判断是否有第二小的值

```
class Solution {
    int min = Integer.MAX_VALUE;
    int flag = 0; //标志min是否被更改
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return -1;
        }
        helper(root, root.val);
        if (flag == 1) { 
            return min;
        }
        return -1;
    }
    public void helper(TreeNode root, int n) {
          if (root == null) {
            return ;
        }
        if (root.val != n) {
            flag = 1;
            min = Math.min(root.val, min);
        } 
        helper(root.left, n);
        helper(root.right, n);  
    } 
}
```


