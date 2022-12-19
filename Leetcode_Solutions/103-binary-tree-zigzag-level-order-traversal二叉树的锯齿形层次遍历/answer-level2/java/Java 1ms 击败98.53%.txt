### 解题思路
核心思想就是写一个boolean控制插入顺序

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if(root==null) return res;
        LinkedList<Integer> list;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        TreeNode temp;
        boolean flag = false;   //控制插入顺序
        while(!q.isEmpty()){
            list = new LinkedList<>();
            for(int i=0,len=q.size();i<len;i++){
                temp = q.poll();
                if(flag) list.addFirst(temp.val);   // true  右->左
                else list.add(temp.val);            // false 左->右
                if(temp.left!=null) q.add(temp.left);
                if(temp.right!=null) q.add(temp.right);
            }
            flag = flag?false:true;
            res.add(list);
        }
        return res;
    }
}
```