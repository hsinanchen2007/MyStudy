# 解法思路（一）
- 还是基于在递归开始时进行“埋点”的思路；
- 埋的这个点就是从递归开始到当前根节点的路径和，随着递归的深入，这个路径和在不断累加；
- 注意对递归到底的情况的讨论：只有在当前根节点不为空并且当前根节点至少有一个孩子的情况下，“埋点”才会累加，进入下一层递归；否则，即当前跟节点为空，或当前跟节点没有左右孩子，都是递归到底的条件；递归到底的时候，就要对问题的结果给出答案；
# 解法实现（一）
###### 时间复杂度
- O(N) ，其中 NN 是节点个数；
###### 空间复杂度
- 最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N 次（树的高度），因此栈的空间开销是 O(N) ；但在最好情况下，树是完全平衡的，高度只有 log(N)，因此在这种情况下空间复杂度只有 O(log(N)) ；
###### 关键字
`二叉树`  `递归` `递归的埋点` 
###### 实现细节
- 因为原方法的参数列表没有定义埋点的位置，因此将问题交由一个新的方法，这个方法的定义中在参数列表中增加了埋点 `int count` 的位置；
```
package leetcode._112;

public class Solution112_1 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public boolean hasPathSum(TreeNode root, int sum) {
        return hasPathSum(root, 0, sum);
    }

    private boolean hasPathSum(TreeNode treeNode, int count, int sum) {

        if (treeNode == null) {
            return false;
        }

        if (treeNode.left == null && treeNode.right == null) {
            return sum == treeNode.val + count;
        }

        count = count + treeNode.val;

        boolean leftHas = hasPathSum(treeNode.left, count, sum);
        boolean rightHas = hasPathSum(treeNode.right, count, sum);

        return leftHas || rightHas;
    }
    
}
```

---

# 解法思路（二）
- 也是基于“埋点”的思想，只不过，没有因加入埋点，而将问题交由一个新方法，而是在原方法的基础上，通过递减过的 `sum` 作为“埋点”在递归中传递； 


# 解法实现（二）
###### 时间复杂度
- O(N) ，其中 NN 是节点个数；
###### 空间复杂度
- 最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N 次（树的高度），因此栈的空间开销是 O(N) ；但在最好情况下，树是完全平衡的，高度只有 log(N)，因此在这种情况下空间复杂度只有 O(log(N)) ；
###### 关键字
`二叉树`  `递归` `递归的埋点` 
###### 实现细节
- 注意递归的时候，把递减的 `sum` 作为“埋点”传入递归的下一层；
```
class Solution {

    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public boolean hasPathSum(TreeNode root, int sum) {

        if(root == null)
            return false;

        if(root.left == null && root.right == null)
            return sum == root.val;

        return hasPathSum(root.left, sum - root.val)
                || hasPathSum(root.right, sum - root.val);
    }
}
```
[返回 LeetCode [Java] 目录](https://www.jianshu.com/p/2cc66577f7d7)

