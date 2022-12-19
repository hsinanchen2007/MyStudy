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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        boolean left = true;
        List<List<Integer>> res = new ArrayList<>();
        List<TreeNode> data = new ArrayList<>();
        if (root != null) {
            data.add(root);
        } else {
            return res;
        }
        List<TreeNode> t2=new ArrayList<>();

        while (data.size() > 0) {
            int size = data.size();
            int count = 0;
            List<Integer> temp = new ArrayList<>();
            while (count < size) {
                // 不同的方向，取值点不一样
                TreeNode node = left ? data.remove(0) : data.remove(size - count - 1);
                temp.add(node.val);
                count++;
                if (!left){
                    // 如果是从右开始
                    if (node.right!=null){
                        t2.add(0,node.right);
                    }
                    if (node.left!=null){
                        t2.add(0,node.left);
                    }
                }else {
                    if (node.left != null) {
                        data.add(node.left);
                    }
                    if (node.right != null) {
                        data.add(node.right);
                    }
                }
            }
            if (t2.size()>0){
                data.addAll(t2);
                t2.clear();
            }
            res.add(temp);
            left = !left;
        }
        return res;
    }
}
```