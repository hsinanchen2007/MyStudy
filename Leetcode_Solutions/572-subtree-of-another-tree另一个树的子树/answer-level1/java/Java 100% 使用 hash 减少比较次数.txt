### 解题思路

![image.png](https://pic.leetcode-cn.com/c403671559c8b04bc5a15d5a157c7076c24b6952cb694534d60e00eb3ff5a4de-image.png)


1. 计算 TreeNode t 的 hash 值 a1
2. 递归计算 TreeNode s 的 hash 值 a2, 如果 a1 == a2 则检查两颗子树是否相同

优势: 在某些应用中, 能大量减少比较次数, 选用不同的hash函数, 可以达到不同的效果 

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
    private boolean isSub = false;

    public boolean isSubtree(TreeNode s, TreeNode t) {
        int hash = hash(t);
        int i = hashT(s, hash, t);
        if (i == hash) {
            return checkNode(s, t);
        }

        return isSub;
    }

    private boolean checkNode(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        }
        if (node1 == null || node2 == null) {
            return false;
        }
        if (node1.val != node2.val) {
            return false;
        }
        return checkNode(node1.left, node2.left) && checkNode(node1.right, node2.right);
    }

    private int hash(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return hash(node.left) + hash(node.right) + node.val;
    }

    private int hashT(TreeNode node, int hash, TreeNode t) {
        if (node == null) {
            return 0;
        }
        int hashCur = hashT(node.left, hash, t) + hashT(node.right, hash, t) + node.val;
        if (hashCur == hash) {
            boolean check = checkNode(node, t);
            if (check) {
                isSub = true;
            }
        }
        return hashCur;
    }

}

```