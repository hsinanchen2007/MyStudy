### 解题思路
此处撰写解题思路
其实这个想的时候就是用最简单的方法：遍历树找到偶数，然后遍历再将偶数的二级节点数值相加就行

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
    int v = 0;
    public int sumEvenGrandparent(TreeNode root) {
        traverseTree(root);
        return v;
    }

    private void traverseTree(TreeNode root){
        if(root != null){
            traverseTree(root.left);
            if(root.val%2 == 0){
                if(root.left != null)
                    traverseTreeTwo(root.left);
                if(root.right != null)
                    traverseTreeTwo(root.right);
            }
            traverseTree(root.right);
        }
    }

    private void traverseTreeTwo(TreeNode root){
        if(root.left != null){
            v += root.left.val;
        }
        if(root.right != null){
            v += root.right.val;
        }
    }
}
```