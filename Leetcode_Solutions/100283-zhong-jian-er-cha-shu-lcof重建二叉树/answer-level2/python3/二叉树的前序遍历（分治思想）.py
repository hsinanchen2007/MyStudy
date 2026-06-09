### 方法：分治思想

经验总结：二叉树的问题一般都是分治思想，递归去做。因为二叉树本身就是递归定义的。

解题思路：

+ **前序遍历的第 1 个结点一定是二叉树的根结点**；
+ 在中序遍历中，根结点把中序遍历序列分成了两个部分，左边部分构成了二叉树的根结点的左子树，右边部分构成了二叉树的根结点的右子树。
+ 查找根结点在中序遍历序列中的位置，可以遍历，也可以在一开始就记录下来。

![image.png](https://pic.leetcode-cn.com/8c8abe01c3e93ded3da0d1aebbda99733bb469f7cf9a82a87c9350ddbab7ffc9-image.png){:width=500}




**参考代码 1**：

```Java []
import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}


public class Solution {

    // 使用全局变量是为了让递归方法少传一些参数，不一定非要这么做

    private Map<Integer, Integer> reverses;
    private int[] preorder;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int preLen = preorder.length;
        int inLen = inorder.length;

        // 可以不做判断，因为题目中给出的数据都是有效的
        if (preLen != inLen) {
            return null;
        }

        this.preorder = preorder;

        // 以空间换时间，否则，找根结点在中序遍历中的位置需要遍历
        reverses = new HashMap<>(inLen);
        for (int i = 0; i < inLen; i++) {
            reverses.put(inorder[i], i);
        }

        return buildTree(0, preLen - 1, 0, inLen - 1);
    }

    /**
     * 根据前序遍历数组的 [preL, preR] 和 中序遍历数组的 [inL, inR] 重新组建二叉树
     *
     * @param preL 前序遍历数组的区间左端点
     * @param preR 前序遍历数组的区间右端点
     * @param inL  中序遍历数组的区间左端点
     * @param inR  中序遍历数组的区间右端点
     * @return 构建的新二叉树的根结点
     */
    private TreeNode buildTree(int preL, int preR,
                               int inL, int inR) {
        if (preL > preR || inL > inR) {
            return null;
        }
        // 构建的新二叉树的根结点一定是前序遍历数组的第 1 个元素
        int pivot = preorder[preL];
        TreeNode root = new TreeNode(pivot);

        int pivotIndex = reverses.get(pivot);

        // 这一步得画草稿，计算边界的取值，必要时需要解方程，并不难
        root.left = buildTree(preL + 1, preL + (pivotIndex - inL), inL, pivotIndex - 1);
        root.right = buildTree(preL + (pivotIndex - inL) + 1, preR, pivotIndex + 1, inR);
        return root;
    }
}
```
```Python []
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def __init__(self):
        self.preorder = None
        self.reverses = None

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        pre_size = len(preorder)
        in_size = len(inorder)
        if pre_size != in_size:
            return None

        self.preorder = preorder
        self.reverses = dict()
        for i in range(in_size):
            self.reverses[inorder[i]] = i

        return self.__build_tree(0, pre_size - 1, 0, in_size - 1)

    def __build_tree(self, pre_left, pre_right, in_left, in_right):
        if pre_left > pre_right or in_left > in_right:
            return None

        pivot = self.preorder[pre_left]
        root = TreeNode(pivot)

        pivot_index = self.reverses[pivot]
        root.left = self.__build_tree(pre_left + 1, pivot_index - in_left + pre_left,
                                      in_left, pivot_index - 1)
        root.right = self.__build_tree(pivot_index - in_left + pre_left + 1, pre_right,
                                       pivot_index + 1, in_right)
        return root
```