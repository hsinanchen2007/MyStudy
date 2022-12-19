### 解题思路
后序遍历思路：
深度优先搜索，记录当前路径sum和当前路径元素，节点出栈时，节点路径移除，节点sum移除当前节点值。
叶子节点判断当前路径的sum是否和目标sum相同，相同的，加入到最终的结果集中。

递归思路：
利用回溯思想，记录当前路径sum和节点路径，叶子节点判断是否输出路径，然后递归进入左右子树，最后回到当前层的时候，要把当前节点移除出节点路径，避免影响后序的路径。

### 后序遍历代码

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
   public List<List<Integer>> pathSum(TreeNode root, int sum) {
        // 后序遍历二叉树，找到对应路径，就是深度优先
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack<>();
        LinkedList<Integer> everyResult = new LinkedList<>();
        List<List<Integer>> res = new LinkedList<>();
        int tempSum = 0;
        TreeNode tempNode = root;// 表示上一个已经被访问的孩子
        while(node != null || !stack.isEmpty()){
            if (node != null){
                tempSum += node.val;// 路径和记录
                everyResult.add(node.val);// 当前路径记录
                // 后序遍历常规操作
                stack.push(node);
                node = node.left;
            }else {
                node = stack.peek();
                if (node.right == null || node.right == tempNode){
                    // 是叶子节点，且路径之和与目标值一致，加入结果集
                    if(node.left == null && node.right == null && tempSum == sum) {
                        res.add(new ArrayList<>(everyResult));
                    }
                    // 当前节点处理，要出栈了，移除掉，路径和去掉当前节点
                    everyResult.removeLast();
                    tempSum -= node.val;
                    // 记录上个节点，后序遍历常规操作
                    tempNode = stack.pop();
                    node = null;
                }else {
                    // 进入右子树，不需要其他操作，当前node的处理，在之前的node != null的代码块中已经处理了
                    node = node.right;
                }
            }
        }
        return res;
    }
}
```

### 递归代码

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
   public List<List<Integer>> pathSumByRecursion(TreeNode root, int sum){
        List<List<Integer>> res = new ArrayList<>();
        pathSumRecursion(root,sum,0,new LinkedList<>(),res);
        return res;
    }

    /**
     * 递归求到叶子节点的路径和
     * @param node node
     * @param sum 目标sum
     * @param pathSum 当前路径的sum
     * @param currentPath 当前路径
     * @param res 最终结果
     */
    private void pathSumRecursion(TreeNode node,int sum,int pathSum,Deque<Integer> currentPath,List<List<Integer>> res){
        if (node == null){
            return ;
        }
        // 路径sum和路径记录
        pathSum += node.val;
        currentPath.add(node.val);

        if (node.left == null && node.right == null && pathSum == sum){
            // 为叶子节点，sum相同加入
            res.add(new ArrayList<>(currentPath));
        }else {
            // 递归进入左右子树
            pathSumRecursion(node.left,sum,pathSum,currentPath,res);
            pathSumRecursion(node.right,sum,pathSum,currentPath,res);
        }
        // 回到本层，移除这个节点
        currentPath.pollLast();
    }
}
```