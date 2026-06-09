执行用时 :3 ms, 在所有 Java 提交中击败了84.83%的用户；内存消耗 :37.2 MB, 在所有 Java 提交中击败了85.48%的用户.

### 思路：
我们知道，在前序遍历的时候，根节点是第一个输出，而在后序遍历中，根节点是最后一个输出；

那么我们可以**利用前序遍历来构建Tree，然后通过后续遍历来检验当前树是否构建完毕**。

首先我们创建一个节点作为 root，`root = TreeNode(pre[preIndex])`当 `root.val == post[posIndex]`时, 意味着我们已经构建完毕了当前子树，如果当前子树没有构建完毕，那么我们就递归的构建左右子树。

具体代码:
```Java
int preIndex = 0, posIndex = 0;
public TreeNode constructFromPrePost(int[] pre, int[] post) {
    TreeNode root = new TreeNode(pre[preIndex++]);
    if (root.val != post[posIndex])
        root.left = constructFromPrePost(pre, post);
    if (root.val != post[posIndex])
        root.right = constructFromPrePost(pre, post);
    posIndex++;
    return root;
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！