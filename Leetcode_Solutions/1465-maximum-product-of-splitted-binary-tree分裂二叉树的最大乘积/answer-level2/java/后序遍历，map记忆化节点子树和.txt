### 解题思路
1.每个节点的子树和等于root.val + sum(root.left) + sum(root.right),这里很明显会有重复计算的问题，因为向左右子树递归求积的时候，又要对子树重新取和，这个在第一次求root树节点和的时候，就已经获取到了，所以用个map记忆，减少重复计算。

2.往左右子树递归的时候，当前分隔方式为Math.max((sum-leftSum)*leftSum,(sum-rightSum)*rightSum)，sum-leftSum就表示从左子树分隔后，另一个子树的节点之和了。sum-rightSum亦然。

3.剪枝，我们知道，在两数（a,b）和固定的情况下，a和b的差值越接近，a x b的值越大（均值不等式），按理来说，左树之和a和右树之和b，**|a-b|肯定是从大到小，然后又从小到大**，有点**类似一个开口向上的二次函数**。那么，**只要新的maxCount不再大于max，我们就可以退出递归**，因为接下来的获取到的值，是不可能大于max了。

详情见代码

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
    // 以TreeNode为root的树节点之和
    private Map<TreeNode,Long> nodeValueMap = new HashMap<>();
    private long max = Integer.MIN_VALUE;
    private int mod = 1000000007;// 结果取模数

    /**
     * 分裂二叉树的最大乘积
     * @param root root
     * @return 最大乘积
     */
    public int maxProduct(TreeNode root) {
        maxProduct(root,nodeValueSum(root));
        return (int) (max % mod);
    }

    /**
     * 子树最大乘积
     * @param root root
     * @param sum 树的全部节点之和
     */
    private void maxProduct(TreeNode root,long sum){
        if (root == null){
            return;
        }
        // 左子树节点之和
        long leftSum = nodeValueSum(root.left);
        // 右子树节点之和
        long rightSum = nodeValueSum(root.right);
        long maxSum = Math.max((sum-leftSum)*leftSum,(sum-rightSum)*rightSum);
        if (maxSum > max){
            max = maxSum;
            // 进入左子树
            maxProduct(root.left,sum);
            // 进入右子树
            maxProduct(root.right,sum);
        }
        // 小于就不再递归了，因为左右子树节点之和本身是一个定制，|a-b|的值是一个从大到小，然后又从小到大的。
        // 那么就是在|a-b|最小的时候，a*b最大,（均值不等式），如果maxCount不在大于max了，就没有继续递归的必要了
    }

    /**
     * 节点子树节点之和
     * @param node node
     * @return 子树之和
     */
    private long nodeValueSum(TreeNode node){
        if (node == null){
            return 0L;
        }
        Long sum = nodeValueMap.get(node);
        if (sum != null){
            return sum;
        }else {
            // 节点和
            sum = node.val + nodeValueSum(node.left) + nodeValueSum(node.right);
            // 记忆化
            nodeValueMap.put(node,sum);
        }
        return sum;
    }

}
```