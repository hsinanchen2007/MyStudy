### 解题思路
//按照之字形打印二叉树，可以采用两个栈去存每一层的节点；
//奇数层的节点存入stack1,偶数层的节点存入stack2;
//写代码的时候细心点即可
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
    //按照之字形打印二叉树，可以采用两个栈去存每一层的节点；
    //奇数层的节点存入stack1,偶数层的节点存入stack2;
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);
        int count = 1;
        while(!stack1.isEmpty()||!stack2.isEmpty()){
            List<Integer> list = new ArrayList<>();
            if(count%2!=0){
                while(!stack1.isEmpty()){
                    TreeNode node = stack1.pop();
                    if(node!=null){
                        list.add(node.val);
                        stack2.push(node.left);
                        stack2.push(node.right);
                    }
                }
            }else{
                while(!stack2.isEmpty()){
                    TreeNode node = stack2.pop();
                    if(node!=null){
                        list.add(node.val);
                        stack1.push(node.right);
                        stack1.push(node.left);
                    }
            }

        }
        if(!list.isEmpty()) res.add(list);
            count++;
        }
        return res;
    }
}
```