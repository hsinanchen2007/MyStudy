### 解题思路
按照树的中序遍历顺序,左根右进行递归调用，把遍历的结果加到最终结果。
但要注意java的List.addAll方法的缺陷,当加进去空列表的时候会报错。

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
    public List<Integer> inorderTraversal(TreeNode root) {
         if(root==null){
            return Collections.emptyList();
        }
        if(root.left==null&&root.right==null){
            return Arrays.asList(root.val);
        }
        List<Integer> list = new ArrayList<>();
        if(root.left!=null){
            List<Integer> leftList = inorderTraversal(root.left);
            if(!leftList.isEmpty()){
                list.addAll(leftList);
            }
        }
        List<Integer> rootList = Arrays.asList(root.val);
        list.addAll(rootList);
        if(root.right!=null){
            List<Integer> rightList = inorderTraversal(root.right);
            if(!rightList.isEmpty()){
                list.addAll(rightList);
            }
        }
        return list;
    }
}
```