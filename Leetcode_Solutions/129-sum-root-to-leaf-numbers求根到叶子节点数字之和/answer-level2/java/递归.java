### 解题思路
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
    public int sumNumbers(TreeNode root) {
        //进行判空处理
          if(root==null)
          return 0;
//调用辅助函数
        return  sumNumbersHelper(root,0);
          
    }
//辅助函数的意义在于：经过当前 root 节点之前，已经累计的和是 sum，函数返回从最初根节点经过当前 root 节点达到叶子节点的和。
    public int sumNumbersHelper(TreeNode root,int sum){
//定义当前节点之前累加的和
        int cursum=sum*10+root.val;
//如果当前节点为叶子结点，则直接返回cursum
        if(root.left==null && root.right==null)
        return cursum;

        int res=0;
//如果当前节点不是叶子节点，且其左叶子节点存在，则记录从最开始经过当前 root 再经过它的左孩子到达叶子节点所有的路径之和
        if(root.left!=null){
            res+=sumNumbersHelper(root.left,cursum);
        }
//如果当前节点不是叶子节点，且其左叶子节点存在，则记录从最开始经过当前 root 再经过它的左孩子到达叶子节点所有的路径之和
        if(root.right!=null){
            res+=sumNumbersHelper(root.right,cursum);
        }
        return res;
    }
}
```