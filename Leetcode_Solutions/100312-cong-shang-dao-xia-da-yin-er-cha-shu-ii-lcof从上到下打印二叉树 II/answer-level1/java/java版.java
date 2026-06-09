### 解题思路
1 把二叉树中的每层节点都放进对列中。
2 在存储本层节点的时候把本层节点的左右子节点都放进队列中
注意：
节点进去列时要先进左节点然后进有节点。因为要求从左到右遍历层

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
            List<List<Integer>> res=new ArrayList<>();
            if(root==null) return res;
            Queue<TreeNode> queue=new LinkedList<>();
            queue.add(root);
            while(queue.size()>0){
            List<Integer> list=new ArrayList<>();
            int size=queue.size();
            for(int i=0;i<size;i++){
                TreeNode temp=queue.poll();
                if(temp.left!=null){
                    queue.add(temp.left);
                }
                if(temp.right!=null){
                    queue.add(temp.right);
                }
                list.add(temp.val);
            }
            res.add(list);
        }
        return res;
    }
}
```