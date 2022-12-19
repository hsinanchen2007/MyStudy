### 解题思路
  开始思考出来的错误规律：（1）当待删除节点是叶子节点时，无需考虑，直接删除
 (2)当待删除节点是非叶子节点时，一定能找到中序遍历在比当前点值大一位或者小一位的节点，且这个
 节点一定是叶子节点，所以我们只需要找到对应的父节点，解除父子关系，将这个叶子节点的值设置好

正确思路：（1）找到待删除节点，存储父节点（2）找到中序遍历前一节点或者后一节点，存储父节点；
（3）根据各种情况来考虑如何去删除节点，比如待删除节点是叶子节点，非叶子节点，这些
后面有时间来优化一下代码；

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

![image.png](https://pic.leetcode-cn.com/08894831164602f4ed802c48abbbff6fc85dc5d35ed8582f251154cadeb86317-image.png)

class Solution {
    TreeNode deleteFatherNode;
    TreeNode fatherNode;
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return root;
        }
        TreeNode deleteNode = findDeleteNode(root, key);
        if (root.val == key) {
            deleteNode = root;
        }
        if (deleteNode == null) {
            return root;
        }
        TreeNode preNode = findPreNode(deleteNode);
        if (preNode != null) {
            if (fatherNode != deleteNode) {
                fatherNode.right = preNode.left;
            } else {
                fatherNode.left = preNode.left;
            }
            deleteNode.val = preNode.val;
            return root;
        }
        TreeNode postNode = findPostNode(deleteNode);
        if (postNode != null) {
            if (fatherNode != deleteNode) {
                fatherNode.left = postNode.right;
            } else {
                fatherNode.right = postNode.right;
            }
            deleteNode.val = postNode.val;
        }
        if (postNode == null) {
            if (deleteFatherNode == null) {
                return null;
            } else {
                if (deleteFatherNode.left == deleteNode) {
                    deleteFatherNode.left = null;
                } else {
                    deleteFatherNode.right = null;
                }
            }
            return root;
        }
        return root;
    }
    public TreeNode findDeleteNode(TreeNode node, int key) {
        TreeNode returnNode = null;
        if (node.left != null) {
            if (node.left.val == key) {
                deleteFatherNode = node;
                return node.left;
            }
            returnNode = findDeleteNode(node.left, key);
        }
        if (returnNode != null) {
            return returnNode;
        }
        if (node.right != null) {
            if (node.right.val == key) {
                deleteFatherNode = node;
                return node.right;
            }
            returnNode = findDeleteNode(node.right, key);
        }
        return returnNode;
    }
    public TreeNode findPreNode(TreeNode node) {
        TreeNode preNode = null;
        if (node.left != null) {
            fatherNode = node;
            preNode = node.left;
        } else {
            return null;
        }
        while (preNode.right != null) {
            fatherNode = preNode;
            preNode = preNode.right;
        }
        return preNode;
    }
    public TreeNode findPostNode(TreeNode node) {
        TreeNode postNode = null;
        if (node.right != null) {
            fatherNode = node;
            postNode = node.right;
        } else {
            return null;
        }
        while (postNode.left != null) {
            fatherNode = postNode;
            postNode = postNode.left;
        }
        return postNode;
    }
    
}
```