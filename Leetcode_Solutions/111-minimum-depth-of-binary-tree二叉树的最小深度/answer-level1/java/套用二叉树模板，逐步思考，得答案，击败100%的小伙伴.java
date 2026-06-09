### 解题思路
首先：明确一个节点要做的事情，然后剩下的事就抛给下面框架。
    void traverse(TreeNode root) {
        // root 需要做什么？在这做。
        // 其他的不用root操心，抛给框架
        traverse(root.left);
        traverse(root.right);
    }

对于本题而言！
我的思考思路：
1.运用上面框架，找到当前节点左子树的最小深度minDepth(root.left)
2.找到右子树的最小值深度minDepth(root.right)
3.选取左子树和右子树的最小深度加上当前节点的深度1即	Math.min(minDepth(root.left), minDepth(root.right)) + 1
于是我第一次提交的代码为：
```java
public int minDepth(TreeNode root) {
          if ( root == null )
          return 0;
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
}

```

提交结果提示我：输入【2,1】 预期输入：2 我的输出：1
看到这个结果，我恍然大悟，原来当某个节点只有左子树或右子树时，应当直接返回左子树的最小深度或右子树的最小深度。
于此，我的改进：
```java
if ( root == null )
    return 0;
if ( minDepth(root.left) == 0 ) return minDepth(root.right) + 1;// 这里可以优化，不需要重复去调用minDepth，使用null代替
if ( minDepth(root.right) == 0 ) return minDepth(root.left) + 1;
return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
```
此代码超时：
检查发现，minDepth==0即使，此节点不存在于是最终改进代码为提交代码如下所示！
![image.png](https://pic.leetcode-cn.com/ab11911328dca0945bf45045f828486b54e7d155467b17e07b49bda0636315b7-image.png)
![image.png](https://pic.leetcode-cn.com/76811914f6fc2451e8859be208c189de040d8f782fe9f18b3aa9980aad00ec75-image.png)


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
           if ( root == null )
            return 0;
        if ( root.left == null ) return minDepth(root.right) + 1;
        if ( root.right == null ) return minDepth(root.left) + 1;
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}
```