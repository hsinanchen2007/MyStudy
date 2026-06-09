深度遍历，每次sum减去节点值，当节点到达底部时检测sum值是否为0，如果为0则加入listList
```
class Solution {
    
    List<List<Integer>> listList = new ArrayList<>();
    List<Integer> integerList = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        findTreePathSum(root,sum);
        return listList;
    }

        public void findTreePathSum(TreeNode treeNode, int sum) {
        if (treeNode == null) {
            return;
        }

        integerList.add(treeNode.val);
        sum -= treeNode.val;

        if (treeNode.left == null && treeNode.right == null && sum == 0
        ) {
            listList.add(new ArrayList<>(integerList));
        }

        if (treeNode.left != null) {
            findTreePathSum(treeNode.left, sum);
        }

        if (treeNode.right != null) {
            findTreePathSum(treeNode.right, sum);
        }

        integerList.remove(integerList.size() - 1);
    }
}
```