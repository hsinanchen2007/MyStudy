> 解题

1. `t`树中若存在和为`sum`的通路`path`
2. `path`必然经过左子树`lt` 与 右子树 `rt`
3. 且左子树必存在通路之和为 $sum - lt.val$; 右子树同理. 
4. 回溯思想在于, 遍历完一条通路后发现不是目标通路, 需要恢复到上一层的状态. 使用压栈与出栈来实现.  

> 画图理解 

![image.png](https://pic.leetcode-cn.com/980de12c501b60a3e0ab1e4d967212e19be8f117efd2040ca7ea1b1840fe902a-image.png)


> 代码

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
    
    List<List<Integer>> result = new LinkedList();
    Stack<Integer> path = new Stack();
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root, sum);
        return result;
    }
    
    public void dfs(TreeNode root, int sum){
        if(root == null) return;
        if(root.left == null && root.right == null){
            path.push(root.val);
            if(root.val == sum){
                result.add(new ArrayList(path));
            }
            path.pop();
            return;
        }
        
        path.push(root.val);
        if(root.left != null) dfs(root.left, sum - root.val);
        if(root.right != null) dfs(root.right, sum - root.val);
        path.pop();
    }
}
```