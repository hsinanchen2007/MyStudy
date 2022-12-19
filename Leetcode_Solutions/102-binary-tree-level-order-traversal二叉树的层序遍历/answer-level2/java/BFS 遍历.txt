### 解题思路
此处撰写解题思路
1、quque 记录每层元素
2、quque.size() ,每层遍历的时候访问完queue每个元素，也就是上一层加入到quque里面的所有元素，这些元素的是同一层的。
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
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) {
            return res ;
        }
        Deque<TreeNode> quque = new LinkedList<>();
        quque.addLast(root);
        while (quque.size() != 0) {
            List<Integer> levelNodes = new ArrayList<>();
            int levelSize = quque.size();
            while(levelSize > 0) {
                TreeNode currNode = quque.pop();
                levelNodes.add(currNode.val);
                if(currNode.left != null) {
                    quque.addLast(currNode.left);
                }
                if(currNode.right != null) {
                    quque.addLast(currNode.right);
                }
                levelSize--;
            }
            res.add(levelNodes);
        }
        return res;

    }
}
```