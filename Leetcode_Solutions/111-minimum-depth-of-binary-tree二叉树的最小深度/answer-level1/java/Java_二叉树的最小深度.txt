### 解题思路
计算二叉树的最小深度，马上联想到计算二叉树的深度，于是：

```java
class Solution {
    public int minDepth(TreeNode root) {
        if(root==null) return 0;//空节点
        int left= minDepth(root.left);//计算左子树的最小深度
        int right=minDepth(root.right);//计算右子树的最小深度
        return 1+Math.min(left,right);//取左右较小者
    }
}
```
然而，用例为[1,2]都报错了，问题出在哪？仔细核对，不难看出，该树的最小深度为2，而上述代码计算左子树最小深度为1，右子树最小深度为0，因此最小深度为1+（1>0?0:1）=1！！ 
要考虑节点的各种情况：
1. 空节点，返回0；
2. 叶子节点，返回1；
3. 左空右非空，返回1+minDepth(right)；
4. 右空左非空，返回1+minDepth(left)；
5. 左右子树非空，返回1+Math.min(minDepth(left),minDepth(right))。



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
        if(root==null) return 0;//空节点

        if(root.left==null&&root.right==null){//叶子节点
            return 1;
        }
        if(root.left==null&&root.right!=null){//左空右非空
            return 1+minDepth(root.right);
        }
        if(root.left!=null&&root.right==null){//左非空右空
            return 1+minDepth(root.left);
        }
        int left= minDepth(root.left);
        int right=minDepth(root.right);
        return 1+Math.min(left,right);
    }
}
```

考虑不周到的错误，吃一堑长一智!