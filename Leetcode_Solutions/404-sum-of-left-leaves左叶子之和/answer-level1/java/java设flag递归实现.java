解题思路：递归调用时，遇到左节点传flag=true进去，当某个节点的左右节点均为null(即为叶子节点)且flag为真时，则为左叶子，返回该节点的值；

```
class Solution {
        public int sumOfLeftLeaves(TreeNode root) {
            return helper(root,false);
        }

        public int helper(TreeNode root,boolean isLeft){
            if(root == null) {
                return 0;
            }
            if(root.left == null && root.right==null && isLeft) {
                return root.val;
            }
            return helper(root.left,true)+helper(root.right,false);
        }
    }
```



