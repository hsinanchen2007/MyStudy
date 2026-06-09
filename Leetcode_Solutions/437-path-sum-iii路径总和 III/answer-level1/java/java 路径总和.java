### 解题思路
声明一个栈记录从根节点到遍历节点的所有节点，遍历二叉树，每到一个节点计算以当前节点为路径尾，从根节点到当前节点符合条件的路径数目。

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
    private int count=0;    //记录符合条件的路径总数
    private Stack<TreeNode> pathElement = new Stack<>();  //记录从根节点到当前节点的元素
    public int pathSum(TreeNode root, int sum) {
        if(root==null) return count;
        pathElement.push(root);
        //计算以当前节点为路径尾，从根节点到当前节点符合条件的路径数目
        curNode(sum);
        //遍历二叉树
        pathSum(root.left,sum);
        pathSum(root.right,sum);
        
        pathElement.pop();
        return count;
    }
    private void curNode(int sum){
        Stack<TreeNode> s=new Stack<>();
        int temp=0;
        while(!pathElement.isEmpty()){
            temp+=pathElement.peek().val;
            if(temp==sum) count++;
            s.push(pathElement.pop());
        }
        while(!s.isEmpty()){
            pathElement.push(s.pop());
        }
    }
}
```