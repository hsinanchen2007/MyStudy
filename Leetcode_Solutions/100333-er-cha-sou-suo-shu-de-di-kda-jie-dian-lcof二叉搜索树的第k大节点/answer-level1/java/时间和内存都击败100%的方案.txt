### 解题思路

中序遍历BST得到的是有序的序列，中序遍历：左子树-根节点-右子树；题目求第K大，因此采用倒置的中序遍历：右子树-根节点-左子树；
遍历过程中记录节点个数（全局变量 cache数组传递引用），个数为k时保存结果，终止遍历。

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
    public int kthLargest(TreeNode root, int k) {
        // ans 和sum
        // 利用数组传递引用，基本类型是值传递
        int[] cache = {0, 0};
        traceBack(root, cache, k);
        return cache[0];
    }

    private void traceBack(TreeNode father,int[] cache,  int k) {
        if (father!=null) {
            if (father.right != null) {// 右子树
                traceBack(father.right,cache,  k);
            }
            if (++cache[1] == k) {// 父节点
                cache[0] = father.val;
                return;
            }
            if (cache[1] < k && father.left != null) {// 左子树
                traceBack(father.left,cache, k);
            }
        }
    }
}
```