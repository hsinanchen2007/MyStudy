### 解题思路  利用集合的反转方法Collections.revese()，反转其中元素，依次把根、右、左、存入原集合中
，然后翻转一下即可。


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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list=new LinkedList<>();
        Stack<TreeNode> stack=new Stack<>();
        if(root==null) return list;
        stack.push(root);
        TreeNode temp=null;
        while(!stack.isEmpty()){
            temp=stack.pop();
            if(temp.left!=null) stack.push(temp.left);
            if(temp.right!=null) stack.push(temp.right);
            list.add(temp.val);
        }
        Collections.reverse(list);
        return list;
    }
}
```