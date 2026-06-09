深度优先，递归；

退出条件：找到叶子节点；

分别记录在两个list里，最后比较是否相等

```java
class Solution {
    List<Integer> list1 = new ArrayList<>();
    List<Integer> list2 = new ArrayList<>();
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        DFS(root1, list1);
        DFS(root2, list2);
        return list1.equals(list2);
    }
    
    private void DFS(TreeNode node, List<Integer> list) {
        if (node != null) {
            DFS(node.left, list);
            DFS(node.right, list);
            if (node.left == null && node.right == null) {
                list.add(node.val);
            }
        }
    }
}
```