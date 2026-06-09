### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/8e8ba97f063794d12a02a78139237ca6c34799398c4e650b3fd2fca02896c5c6-%E5%9B%BE%E7%89%87.png)
**其实就是从上往下层次遍历，然后用LinkedList头插入快特性**

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return new LinkedList<>();
        List<List<Integer>> lists = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        lists.add(Arrays.asList(root.val));
        int cnt = 1;
        List<Integer> list = new LinkedList<>();
        while (!queue.isEmpty()){
            TreeNode node = queue.poll();
            cnt --;
            if (node.left != null) {
                list.add(node.left.val);
                queue.add(node.left);
            }
            if (node.right != null) {
                list.add(node.right.val);
                queue.add(node.right);
            }
            if (cnt == 0 && list.size() > 0){
                lists.add(0, list); // trick
                list = new LinkedList<>();
                cnt = queue.size();
            }
        }
        return lists;
    }
}
```