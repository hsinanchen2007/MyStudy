### 解题思路
前序序列化：前序搜索整棵树，序列化字符串组成为：当前节点值+左根的序列化字符串+右根的序列化字符串；
如果是null根则返回“#”
最后用hashMap来存储序列化字符串和根节点，注意多次找到的结果存储最后找到的那个根节点

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
    // 这里使用序列化字符串作为key
    Map<String, TreeNode> map;
    Map<String, TreeNode> findMap;
    List<TreeNode> result;
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        map = new HashMap<>();
        findMap = new HashMap<>();
        result = new LinkedList<>();
        if (root == null) {
            return result;
        }
        preorder(root);
        // 看一下有没有list数目大于1的
        for (Map.Entry<String, TreeNode> entry:findMap.entrySet()) {
            result.add(entry.getValue());
        }
        return result;
    }
    public String preorder(TreeNode node) {
        if (node == null) {
            return "#";
        }
        String serial = new String(""+node.val);
        // 递归找到左右子树的序列化字符串
        String leftSerial = preorder(node.left);
        String rightSerial = preorder(node.right);
        serial = serial + leftSerial + rightSerial;
        // 判断是否已经存在此序列化字符串，若有则加入结果map，否则不动
        if (map.get(serial) != null) {
            findMap.put(serial, node);
        } else {
            map.put(serial, node);
        }
        return serial;
    }
   
}
```