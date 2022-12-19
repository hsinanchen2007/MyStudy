### 解题思路
此题考察的就是中序遍历

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
    private List<Integer> list = new ArrayList<>();

    public void midorder(TreeNode node){
        if(node == null){
            return;
        }
        midorder(node.left);
        list.add(node.val);
        midorder(node.right);
    }

    public int kthLargest(TreeNode root, int k) {
        midorder(root);
        if(k > list.size())
            return -1;
        return this.list.get(this.list.size()-k);
    }
}
```