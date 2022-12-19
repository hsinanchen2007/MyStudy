### 解题思路
对于节点root来说，最长路径只可能是以下3种情况：1.只与左子树有关；2.只与右子树有关；3.与root有关

1.只与左子树有关，即root.val != root.left.val
    此时需要知道左子树的最长同值路径信息
2.只与右子树有关，同上
3.与root有关
    需要知道左右子树从它们根节点出发得到的单侧最长等值路径信息，如果root的左右孩子val与其val相等，就可以进行整合

综上，对于任意一个节点，需要为其父节点提供两个信息：以自己为头的子树的最长等值路径长度；以及从头节点出发的最长单侧等值路径
这两个信息可以通过递归获取自己左右子树相关信息后整合得到

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
    // 需要向上级节点返回的信息
    private static class ReturnType{
        // 此节点为head时的最长等值路径长度
        int maxLen;
        // 此节点出发往下走的最长单侧等值路径长度
        int headSingleSideMax;
        public ReturnType(int maxLen, int headSingleSideMax){
            this.maxLen = maxLen;
            this.headSingleSideMax = headSingleSideMax;
        }
    }

    // 递归函数
    private ReturnType process(TreeNode node){
        // base case
        if(node.left == null && node.right == null){
            return new ReturnType(0, 0);
        }

        // headSidesMax表示经过头节点的最长等值路径长度
        int maxLen = 0, headSingleSideMax = 0, headSidesMax = 0;

        // 从左子树获取信息
        if(node.left != null){
            ReturnType left = process(node.left);
            if(node.val == node.left.val){
                headSingleSideMax = 1 + left.headSingleSideMax;
                headSidesMax += 1 + left.headSingleSideMax;
            }
            maxLen = left.maxLen;
        }
        
        // // 从右子树获取信息
        if(node.right != null){
            ReturnType right = process(node.right);
            if(node.val == node.right.val){
                headSingleSideMax = Math.max(headSingleSideMax, 1 + right.headSingleSideMax);
                headSidesMax += 1 + right.headSingleSideMax;
            }
            maxLen = Math.max(maxLen, Math.max(right.maxLen, headSidesMax));
        }

        // 返回本节点整合后的信息
        return new ReturnType(maxLen, headSingleSideMax);
    }

    public int longestUnivaluePath(TreeNode root) {
        if(root == null)
            return 0;
        ReturnType rt = process(root);
        return Math.max(rt.maxLen, rt.headSingleSideMax);
    }
}
```