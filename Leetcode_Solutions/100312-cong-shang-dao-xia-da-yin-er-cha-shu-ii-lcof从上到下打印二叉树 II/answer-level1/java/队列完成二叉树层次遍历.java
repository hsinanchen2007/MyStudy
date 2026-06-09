### 解题思路
主要的思想是用队列来完成二叉树的层次遍历，这里想的有点多了，有了个双队列来区分层次，其实内层循环用for循环就可以。

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
        
        Queue<TreeNode> A = new LinkedList<>();
        Queue<TreeNode> B = new LinkedList<>();
        A.add(root);

        while(!A.isEmpty()||!B.isEmpty()){
            List<Integer> lineA = new ArrayList<>();
            while (!A.isEmpty()){
                TreeNode front = A.poll();
                lineA.add(front.val);
                if(front.left!=null){ B.add(front.left); }
                if(front.right!=null){ B.add(front.right); }
            }
            if(!lineA.isEmpty()) resulet.add(lineA);

            List<Integer> lineB = new ArrayList<>();
            while (!B.isEmpty()){
                TreeNode front = B.poll();
                lineB.add(front.val);
                if(front.left!=null){ A.add(front.left); }
                if(front.right!=null){ A.add(front.right); }
            }
            if(!lineB.isEmpty()) resulet.add(lineB);
        }
        return resulet;
    }
}
```