### 解题思路
新来的节点在数组的最右侧，那么这个节点肯定要往右子树添加。(**因为新节点加在数组的末尾，其他节点在方位上，都应该在新节点的左侧**)也就是说，**比新节点大的点，新节点应该是它的右孩子，比新节点小的点，它是新节点的左孩子**。

1.如果他是最大的，直接改变root,整个树都是他的左孩子。
2.往右子树迭代，只要当前node.val >= val，就需要往右子树迭代，同时记录下最近一个大于val的节点(bigNode)，便于后续节点加入，交换指针。
3.如果发现node.right为空，则新节点直接加入到node.right即可。代码完成
4.迭代中，如果node.val < val了，这时候新的newNode就是bigNode的右孩子(取代之前node的位置)，node.val < newNode.val，则node就是newNode的左孩子。

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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null){
            return null;
        }
        if (root.val < val){
            TreeNode newNode = new TreeNode(val);
            newNode.left = root;// 当前值最大，小于当前值的节点都在数组左侧
            return newNode;
        }
        // 记录最近一个比val大的node节点
        // 不需要使用Map来缓存，因为不需要往父节点遍历，只需要记录一个
        TreeNode bigNode = root;
        TreeNode node = root;
        // node不会是null,如果node.right是null的时候，就直接返回了，不会继续往右子树遍历了
        while (node.val >= val){
            if (node.right == null){
                node.right = new TreeNode(val);// 新的节点都在右侧
                return root;// 直接返回了
            }else {
                // 记录下最近较大的元素
                bigNode = node;
                // 只能往右侧查找，新加入的值在右边
                node = node.right;
            }
        }
        TreeNode newNode = new TreeNode(val);
        // 节点加入，交换指针。bigNode比newNode大，newNode要取代之前node所在的位置
        // 旧的节点比新节点大，肯定在新节点的左边，所以新节点为旧节点的右孩子
        bigNode.right = newNode;
        // 原来的节点比新节点小，新节点加在右侧，那旧节点就为他的左孩子
        newNode.left = node;
        return root;
    }
}
```