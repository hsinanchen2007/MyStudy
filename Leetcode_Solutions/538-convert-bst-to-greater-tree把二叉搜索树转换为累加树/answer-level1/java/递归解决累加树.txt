### 解题思路
![累加树.png](https://pic.leetcode-cn.com/d80391b26950cdab22ac451bdf37cf9fb4bb5e4e79dcb55c4f90ed6966bc3954-%E7%B4%AF%E5%8A%A0%E6%A0%91.png)

1.这个题本质上是考察二叉树的遍历模型，先遍历右子树，再遍历根结点，最后遍历左子树。
唯一要考虑的事是怎么将累加和传递给下一个结点，这里我用了一个变量preSum来记录这个累积和。
时间复杂度O(n)
空间复杂度O(1)
2.更直观的做法是，将所有结点按右->根->左的顺序入List，然后从尾部倒序访问整个list，依次做累加。
时间复杂度O(n)
空间复杂度O(n)

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

    private int preSum = 0;
    public TreeNode convertBST(TreeNode root) {
        if(root == null)
            return root;
        convertBST(root.right);
        root.val += preSum;
        preSum = root.val;
        convertBST(root.left);
        return root;
    }
}
```