### 解题思路
此处撰写解题思路

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
    public int kthLargest(TreeNode root, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        helper(root,list);
        return list.get(list.size()-k);
    }
    //辅助函数
    public void helper(TreeNode root,ArrayList<Integer> list){
        if(root == null) return;
        //进行中序遍历，添加节点的值
        helper(root.left,list);
        list.add(root.val);
        helper(root.right,list);
    }
}
```