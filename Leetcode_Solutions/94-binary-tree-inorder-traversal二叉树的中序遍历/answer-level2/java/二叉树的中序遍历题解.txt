### 解题思路
对于这类问题，把它直接看成只有三个节点（根节点，左子树，右子树）的树，不需要展开，直接调用。

先建立两个list里面的类型是Integer包装类型，一个放根节点的左子树的前序遍历（这一块会有很多次的调用），另一个放根节点的右子树的前序遍历，然后再新建立一个list，用list的addAll()方法依次将左子树，根节点，右子树放在一起，最后将这个list返回。

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
        if(root == null){
            return new ArrayList<>();
        }
        List<Integer> left = inorderTraversal(root.left);
        List<Integer> right = inorderTraversal(root.right);
        List<Integer> list = new ArrayList<Integer>();
        list.addAll(left);
        list.add(root.val);
        list.addAll(right);
        return list;

    }
}
```