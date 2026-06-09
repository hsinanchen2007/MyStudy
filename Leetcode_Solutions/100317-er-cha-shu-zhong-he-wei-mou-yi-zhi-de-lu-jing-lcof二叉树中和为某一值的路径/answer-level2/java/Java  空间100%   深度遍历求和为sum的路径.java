### 解题思路
二叉树深度优先遍历算法的实现
1. path存储当前节点值
2. 当sum为0则表示找到一个sum符合的，但是同时需要检查当前root是不是叶子节点
3. 如果是叶子节点则添加该路径到result变量中 
**Note：添加path的时候需要重新new一个，不然随着递归的结束，原先path引用指向的对象已经清空**
4. 最后一定要删除当前路径path上的当前节点，递归回去处理下一个分支

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
    // 使用LinkedList，提供了removeLast方法
    private List<List<Integer>> result = new LinkedList<>();
    private LinkedList<Integer> path = new LinkedList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) {
            return new ArrayList<>();
        }

        func(root, sum);
        return result;
    }

    // 二叉树深度优先遍历算法的实现
    // 同时加上路径的存储以及更新
    // 当sum为0则表示找到一个sum符合的，但是同时需要检查当前root是不是叶子节点
    // 如果是叶子节点则添加该路径到result变量中
    // 最后一定要删除当前路径path上的当前节点，递归回去处理下一个分支
    private void func(TreeNode root, int sum) {
        if (root == null ) {
            return;
        }

        path.add(root.val); // 将当前节点添加在path上
        sum -= root.val; // 更新下次寻找的sum值
        // 如果sum此时为0且left与right为null即root为叶子节点，
        // 则此路径是一个合法结果，添加在result中
        if (sum == 0 && root.left == null && root.right == null) {
            // Note:添加path的时候需要重新new一个，不然随着递归的结束，原先path引用指向的对象已经清空
            result.add(new LinkedList(path));
        }

        // 递归处理left与right
        func(root.left, sum);
        func(root.right, sum);

        // 该节点处理完成之后将其从路径中删除，递归回去处理其他分支
        path.removeLast();
    }
}
```