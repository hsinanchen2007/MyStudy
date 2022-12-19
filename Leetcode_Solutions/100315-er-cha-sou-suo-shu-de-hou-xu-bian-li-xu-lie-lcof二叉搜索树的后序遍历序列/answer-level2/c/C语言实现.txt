### 解题思路
此处撰写解题思路

执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了100.00%的用户

在后续遍历中，最后一个数字是树的根节点的值，数组中前面的数字可以分为两部分：第一部分是左子树的值，它们都比根节点的值要小；第二部分是右子树结点的值，它们都比根节点的值要大。

如果面试题中要求处理一颗二叉树的遍历序列，我们可以先找到二叉树的根节点，在基于根节点把整棵树的遍历序列拆分成左子树对应的子序列和右子树对应的子序列，接下来再递归处理这两个子序列。


### 代码

```c
bool verifyPostorder(int* postorder, int postorderSize){
    if (postorder == NULL || postorderSize <= 0) {
        return true;
    }

    int val = postorder[postorderSize - 1];
    int iLeft = 0;
    while (iLeft < postorderSize - 1) {
        if (postorder[iLeft] < val) {
            iLeft++;
        } else {
            break;
        }
    }

    int jRight = iLeft;
    while (jRight < postorderSize - 1) {
        if (postorder[jRight] < val) {
            return false;
        }
        jRight++;
    }

    bool left = true;
    if (iLeft > 0) {
        left = verifyPostorder(postorder, iLeft);
    }

    bool right = true;
    if (iLeft < postorderSize - 1) {
        right = verifyPostorder(postorder + iLeft, postorderSize - iLeft - 1);
    }

    return left && right;
}
```