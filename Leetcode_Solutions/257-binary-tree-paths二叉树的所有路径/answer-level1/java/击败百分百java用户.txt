### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> resultList = new LinkedList<>();
        binaryTreePaths(root, new StringBuilder(), resultList);
        return resultList;
    }

    private void binaryTreePaths(TreeNode node,StringBuilder sb,List<String> resultList) {
        if (node == null) {
            return;
        }
        if (isLeaf(node)) {
            sb.append(node.val);
            resultList.add(sb.toString());
            return;
        } else {
            sb.append(node.val).append("->");
        }
        binaryTreePaths(node.left,new StringBuilder().append(sb),resultList);
        binaryTreePaths(node.right,new StringBuilder().append(sb),resultList);
    }


    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
```