要求处理一棵二又树的遍历序列，则可以先找到二叉树的根节点，再基于根节点把整棵树的遍历序列拆分成左子树对应的子序列和右子树对应的子序列，接下来再递归地处理这两个子序列。本题应用的是这种思路，第7题“重建二叉树"应用的也是这种思路。

> 本题是后序遍历，所以最后一个元素肯定是整个当前树的根节点

思路：根据`左，右，后`的顺序可以确定根节点；根据 `左 < 后`，`右 > 后` 可以划分左右子树（使用下标划分左右子序列）
```Java
    public boolean verifyPostorder(int [] postorder) {
        if (postorder.length <= 2) return true;
        return verifySeq(postorder, 0, postorder.length-1);
    }
    private boolean verifySeq(int[] postorder, int start, int end) {
        if (start >= end) return true;
        int i;
        for (i = start; i < end; i++) {
            if (postorder[i] > postorder[end]) break;
        }
        // 验证后面的是否都大于sequence[end]
        for (int j = i; j < end; j++) {
            if (postorder[j] < postorder[end]) return false;
        }
        return verifySeq(postorder, start, i-1) && verifySeq(postorder, i, end-1);
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！