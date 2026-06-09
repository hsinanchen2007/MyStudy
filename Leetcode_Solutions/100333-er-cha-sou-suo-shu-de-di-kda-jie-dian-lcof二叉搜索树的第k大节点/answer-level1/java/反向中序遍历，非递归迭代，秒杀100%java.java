### 解题思路
通过反向中序遍历，当遍历到第k个节点时，直接返回改节点值，如果未找到，则返回0
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
    // 反向中序遍历，当遍历到第k个节点时，返回该节点值
    public int kthLargest(TreeNode root, int k) {
        // count用于指示已经查找过的数字个数
        int count=0;
        TreeNode p= root;
        Stack<TreeNode> stack=new Stack<>();
        while(p!=null||!stack.isEmpty()){
            if(p!=null){
                stack.push(p);
                p=p.right;
            }else{
                p=stack.pop();
                count++;
                if(count==k) return p.val;
                p=p.left;
            }
        }
        return 0;
    }
}
```