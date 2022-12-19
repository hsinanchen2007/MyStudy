### 解题思路
递归，进入左子树的时候，加一个标志位；使用全局int变量

### 代码

```java

class Solution {
    // 全局sum
    int sum = 0;

    public int sumOfLeftLeaves(TreeNode root) {
        cal(root, 0);
        return sum;
    }

    // flag为标志变量
    void cal(TreeNode root, int flag){
        if(root == null)
            return;

        if(root.left == null && root.right == null){
            if(flag == 1){
                sum += root.val;
            }
            return;
        }
        cal(root.left, 1);
        cal(root.right, 2);       
    }
}
```