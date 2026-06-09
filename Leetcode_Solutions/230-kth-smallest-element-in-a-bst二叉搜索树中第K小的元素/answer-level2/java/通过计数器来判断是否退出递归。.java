### 从左边开始遍历，遍历完左边分支，计数器temp加1，当temp和k相等的时候，即找到了要求的值，并通过抛错误强制退出递归，此时theanswer即为要求的值；如果temp和k不相等，去找右边的分支，如果完全找不到，返回-1。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    Integer temp=0;
    Integer theanswer=-1;
    public void dfs(TreeNode root,int k)throws Exception {
        if (root != null) {
                dfs(root.left, k);
                temp++;
                if(temp==k) {
                    theanswer=root.val;
                    throw  new Exception();
                }
                dfs(root.right, k);
            }
    }
    public int kthSmallest(TreeNode root, int k) {
        try {
            dfs(root, k);
        }catch (Exception e){

        }
        return theanswer;
    }
}
```