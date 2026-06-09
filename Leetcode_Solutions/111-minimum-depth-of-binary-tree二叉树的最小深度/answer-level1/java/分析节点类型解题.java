### 解题思路
#  1.首先有三种节点，叶子节点，普通节点，和null节点
#  2.null节点有：叶子节点左右孩子、根节点为null，普通节点左右其中一个为null(非叶子节点其中一种)


![未命名文件.png](https://pic.leetcode-cn.com/e5e60d201ad7a191484789ac214cb11e62b8e6fb4c52d23d8ebab81b3cc35fad-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)




# 对于null节点：直接返回0；

# 对于普通节点：判断其左右是否有null节点，有则返回最大深度 Max(left,right),无null节点则返回最小深度Min(left,right);

# 非叶子节点返回最大深度 Max(left,right)原因：
*  普通节点因为不是叶子节点，如果有左右子树有null，则深度为 (0,n)
*  此时应该取最大深度：n


# 非叶子节点返回最小深度 Min(left,right)原因：
* 普通节点左右子树不为空，则left和right其中一个必然是该节点的最小深度
* 此时应取最小的深度


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

    public int minDepth(TreeNode root) {
        if(root==null)return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        if(left==0||right==0)
            return Math.max(left,right)+1;
        return Math.min(left,right)+1;

    }
}




