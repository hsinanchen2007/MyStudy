### 解题思路
还不太会用双端队列，就用了双栈来解决，但是用栈时注意遍历偶数行的同时，将下一层奇数行入栈，必须右子树先入，左子树后入，才能不使数据发生错乱。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> resulet = new ArrayList<>();
        if(root==null) return resulet;

        Deque<TreeNode> A = new LinkedList<>();
        Deque<TreeNode> B = new LinkedList<>();
        A.add(root);
        while(!A.isEmpty()||!B.isEmpty()){
            List<Integer> lineA = new ArrayList<>();
            while (!A.isEmpty()){
                TreeNode top = A.pop();
                lineA.add(top.val);
                if(top.left!=null){ B.push(top.left); }
                if(top.right!=null){ B.push(top.right); }
            }
            if(!lineA.isEmpty()) resulet.add(lineA);

            List<Integer> lineB = new ArrayList<>();
            while (!B.isEmpty()){
                TreeNode top = B.pop();
                lineB.add(top.val);
                if(top.right!=null){ A.push(top.right); }
                if(top.left!=null){ A.push(top.left); }
            }
            if(!lineB.isEmpty()) resulet.add(lineB);
        }
        return resulet;
    }
}
```