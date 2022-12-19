### 解题思路
此处撰写解题思路
利用TreeSet的有序且不重复特性，遍历二叉树将值添加到TreeSet中，如果集合中只有一个数，说明不存在第二小的值，此时返回负一，否则返回第二个数。

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
    TreeSet<Integer> set=new TreeSet<>();
    public int findSecondMinimumValue(TreeNode root) {
        help(root);
        if(set.size()<=1){
            return -1;
        }
        else return set.higher(set.first());

    }
    public void help(TreeNode root){
        if(root==null)return;
        if(root!=null){
            set.add(root.val);

        }
        
        help(root.left);
        help(root.right);
        
    }
}
```