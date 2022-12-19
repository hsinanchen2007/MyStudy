### 解题思路
遍历两个树，把两个树的叶子结点放入数组中，然后比较这两个数组中的元素是否相等即可。

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if(root1==null||root2==null) return false;
        if(root1==null&&root2==null) return true;
        List<Integer> list1=new ArrayList<Integer>();
        List<Integer> list2=new ArrayList<Integer>();
        helper(root1,list1);
        helper(root2,list2);
        return list1.equals(list2);
    }
    public void helper(TreeNode root,List<Integer> list){
        if(root!=null){
            if(root.left==null&&root.right==null){
                list.add(root.val);
            }
        }
       if(root!=null) helper(root.left,list);
       if(root!=null) helper(root.right,list);
    }
}
```