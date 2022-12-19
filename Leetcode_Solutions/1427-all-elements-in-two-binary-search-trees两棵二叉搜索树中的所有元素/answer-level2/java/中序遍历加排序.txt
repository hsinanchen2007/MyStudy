### 解题思路
中序递归遍历，然后使用Collections.sort(list)方法即可解决

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


    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> list = new ArrayList<>();
        preOrder(root1, list);
        preOrder(root2, list);
        Collections.sort(list);
        return list;
    }

    public void preOrder(TreeNode root, List list){
        if(root != null){
            list.add(root.val);
            preOrder(root.left, list);
            preOrder(root.right, list);
        }
    }
}
```