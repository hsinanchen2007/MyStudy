### 解题思路
1.利用二叉搜索树查找元素的思路，首先定位到剪枝之后的根节点。
2.继续通过二叉搜索树查找元素，利用双指针，一个指针遍历，另一个指针记录满足条件的当前节点，满足条件的指针接上，不满足则置空。
3.L和R的思路一样，按照对称性反过来即可

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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        TreeNode newRoot = null;
        TreeNode node = root;
        while (node != null){
            if (L <= node.val && node.val <= R){
                newRoot = node;// 找到剪枝后的根节点
                break;
            }else if(node.val < L){
                node = node.right;
            }else {
                node = node.left;
            }
        }
        if (newRoot == null){
            return null;
        }
        // L处理
        TreeNode tempNode = newRoot;
        node = newRoot.left;
        while (node != null){
            if (node.val > L){
                // 左指针接上
                tempNode.left = node;
                // 临时指针左移
                tempNode = node;
                node = node.left;
            }else if (node.val < L){
                // 数值小的，不要了
                tempNode.left = null;
                node = node.right;
            }else {
                // 左指针接上
                tempNode.left = node;
                // 最小值匹配到，比他小的都不要了
                node.left = null;
                break;
            }
        }
        // R值处理
        tempNode = newRoot;
        node = newRoot.right;
        while (node != null){
            if (node.val > R){
                // node.val比最大值还大的，不要了
                tempNode.right = null;
                node = node.left;
            }else if (node.val < R){
                // 右指针接上
                tempNode.right = node;
                // 临时指针右移
                tempNode = node;
                node = node.right;
            }else {
                // 右指针接上
                tempNode.right = node;
                // 最大值匹配到，比他大的都不管了
                node.right = null;
                break;
            }
        }
        return newRoot;
    }
}
```