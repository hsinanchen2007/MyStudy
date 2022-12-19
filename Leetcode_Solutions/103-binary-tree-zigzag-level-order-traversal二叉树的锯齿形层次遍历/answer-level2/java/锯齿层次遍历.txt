### 解题思路
第一次ac：每轮层次遍历若需反向（从右到左），则用一个栈暂存当前层节点，然后再出栈，存到结果中去
导致运行时间加长，增加在进栈出栈时间上面，
第二次：每轮层次遍历若需反向，则直接在动态数组中加到头部，正向则加到动态数组尾部；
第一次思考时间过长主要关注到如何去保证在遍历每层节点时，能否直接正向或者反向将子节点加到数组中去，
这样下一轮遍历就非常方便，反而忽略了无需对子节点正向反向加入数组，其实只需要关注如何去正向反向增加
值即可，多思考一种可能性，切记切记。

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
        if (root == null) {
            return new ArrayList<>();
        }
        // 记录当前层的所有节点
        LinkedList<TreeNode> levelNodeList = new LinkedList<>();
        // 记录所有的节点
        List<List<Integer>> result = new LinkedList<>();
        // 每加一层变方向,true是从左到右，false是从右到左
        boolean flag = true;
        levelNodeList.add(root);
        int levelSize = levelNodeList.size();
        while (true) {
            LinkedList<Integer> levelResult = new LinkedList<>();
            for (int i=0;i<levelSize;i++) {
                TreeNode node = levelNodeList.remove();
                if (flag) {
                    levelResult.add(node.val);
                } else {
                    levelResult.add(0,node.val);
                }
                if (node.left != null) {
                    levelNodeList.add(node.left);
                }
                if (node.right != null) {
                    levelNodeList.add(node.right);
                }
            }
            result.add(levelResult);
            levelSize = levelNodeList.size();
            if (levelSize == 0) {
                break;
            }
            flag = !flag;
        }
        return result;
    }
}
```