# 解法思路（一）
- 路径的开头可以不是根节点，结束也可以不是叶子节点，是不是有点复杂？
- 如果问题是这样：找出以根节点为开始，任意节点可作为结束，且路径上的节点和为 sum 的路径的个数；
- 是不是前序遍历一遍二叉树就可以得到所有这样的路径？是的；
- 如果这个问题解决了，那么原问题可以分解成多个这个问题；
- 是不是和数线段是同一个问题，只不过线段变成了二叉树；
- 在解决了以根节点开始的所有路径后，就要找以根节点的左孩子和右孩子开始的所有路径，三个节点构成了一个递归结构；
- 递归真的好简单又好难；

# 解法实现（一）
###### 时间复杂度
- O(n)，n为树的节点个数；
###### 空间复杂度
- O(h)，h为树的高度；
###### 关键字
`二叉树` `递归` `前序遍历` `路径和` `路径数量` `数线段` `双递归`
###### 实现细节
- `sum - root.val` 好好体会一下，挺有意思的；
```
package leetcode._437;

public class Solution437_1 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    /**
     * 求以 root 为根的二叉树，所有和为 sum 的路径；
     * 路径的开头不一定是 root，结尾也不一定是叶子节点；
     * @param root
     * @param sum
     * @return
     */
    public int pathSum(TreeNode root, int sum) {

        if (root == null) {
            return 0;
        }

        return paths(root, sum) 
                + pathSum(root.left, sum) 
                + pathSum(root.right, sum);
    }

    private int paths(TreeNode root, int sum) {

        if (root == null) {
            return 0;
        }

        int res = 0;
        if (root.val == sum) {
            res += 1;            
        }
        
        res += paths(root.left, sum - root.val);
        res += paths(root.right, sum - root.val);
        
        return res;
    }

}
```
[返回 LeetCode [Java] 目录](https://www.jianshu.com/p/2cc66577f7d7)