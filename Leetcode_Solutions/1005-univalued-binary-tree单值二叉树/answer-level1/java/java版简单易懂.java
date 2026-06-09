### 解题思路
把先序遍历的结果存放在数组中，然后把数组中的元素前后两两比较，遇到前后两个元素不相等的值直接返回false结束循环

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
    List<Integer> list=new ArrayList<Integer> ();
    boolean flag=true;
    public boolean isUnivalTree(TreeNode root) {
        if(root==null) return true;
         helper(root);
         for(int i=0;i<list.size()-1;i++){
                if(list.get(i+1)!=list.get(i)){
                    flag=!flag;
                    break;
                }else{
                    flag=flag;
                }
         }
            return flag;
}
public void helper(TreeNode root){
    if(root==null) return;
    list.add(root.val);
    helper(root.left);
    helper(root.right);
}
}
```