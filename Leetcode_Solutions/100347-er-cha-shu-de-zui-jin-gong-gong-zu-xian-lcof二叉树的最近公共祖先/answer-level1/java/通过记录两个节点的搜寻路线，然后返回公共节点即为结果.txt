### 解题思路
1. 新建一个DFS函数，分别传入p节点和q节点
2. 得出两个节点的路线数组
3. 拿出两个数组里面相同的节点返回

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> foundP = find(root, p);
        List<TreeNode> foundQ = find(root, q);
        foundP.retainAll(foundQ); //获取相同的节点
        return foundP.get(0); //返回题目要求的最近那个父节点也就是第一个
    }

    private List<TreeNode> find(TreeNode node, TreeNode target){
        if(node.val == target.val){ //如果找到目标节点就返回一个list用于记录路线
            List<TreeNode> list = new ArrayList<TreeNode>();
            list.add(node);
            return list;
        }
        TreeNode left = node.left;
        TreeNode right = node.right;

        List<TreeNode> collector = new ArrayList<TreeNode>();
        if(left != null)collector.addAll(find(left, target)); //左边搜寻
        if(right != null)collector.addAll(find(right, target)); //右边搜寻。实际上如果left找到了东西就不需要这步了，因为题目说明是每个节点的值是唯一的

        if(!collector.isEmpty())collector.add(node); //如果搜寻到了的话，就把父节点记录下来
        return collector;
    }
}
```