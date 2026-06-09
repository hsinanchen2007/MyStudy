### 解题思路
使用递归方法实现子节点填充

前序遍历结构为[根节点|左子树|右子树]
中序遍历结构为[左子树|根结点|右子树]

步骤：
1、前序列表的第一个数字都是根结点
2、取该数字在中序列表的index
3、index的左边的个数即左子树的节点数，右边即右子树的节点数
4、前序列表从第二个下标开始，取相同个数的数组串即为左子树的前序遍历，剩下的右半个数组串即为右子树的前序遍历

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length ==0) {
            return null;
        }
        List<Integer> inorderList = Arrays.stream(inorder)
                .boxed().collect(Collectors.toList());
        List<Integer> preorderList = Arrays.stream(preorder)
                .boxed().collect(Collectors.toList());
        TreeNode root = new TreeNode(preorderList.get(0));
        Integer inorderHead = inorderList.indexOf(preorderList.get(0));
        if (inorderHead > 0) {
            root.left = buildTree(
                    preorderList.subList(1, 1+inorderHead)
                            .stream().mapToInt(Integer::valueOf).toArray(),
                    inorderList.subList(0, inorderHead)
                            .stream().mapToInt(Integer::valueOf).toArray());
        }
        if (inorderHead < inorderList.size()-1) {
            root.right  = buildTree(
                    preorderList.subList(1+inorderHead, preorderList.size())
                            .stream().mapToInt(Integer::valueOf).toArray(),
                    inorderList.subList(inorderHead+1, inorderList.size())
                            .stream().mapToInt(Integer::valueOf).toArray());
        }
        return root;
    }
}
```