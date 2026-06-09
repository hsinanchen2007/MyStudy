> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/9b75e5f613b30c780b836006a0a2d855d2a5e09b6d8dad95b77f9c5d3408640b-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


> 竟然甩给我一道算法题做，太可恶了嘤嘤嘤。

## 题目链接
[LeetCode 99. 恢复二叉搜索树](https://leetcode-cn.com/problems/recover-binary-search-tree/ "LeetCode 99. 恢复二叉搜索树")

## 题解
先不考虑空间复杂度，因为二叉搜索树的中序遍历是单调递增的，所以我们只需要求出它的中序遍历。然后两个结点被调换过位置，等价于递增序列中两个数调换了位置。那么我们只需要找出序列中第一个逆序对（前一个数）和最后一个逆序对（后一个数）就行了，然后换回它俩的位置。

但是中序遍历无论使用递归实现还是栈实现，空间复杂度都是树的高度，不是常数。

想一下为什么我们需要用递归或者栈来实现中序遍历？因为从根结点开始进入左子树之后，遍历完了左子树还需要回到根结点，然后再进入右子树继续遍历。但是如果你没有栈，你就没法从左子树回到根结点了，因为左子树中没有结点能指到根结点。

我们需要解决的就是这个问题，这里我们引入 **Morris 遍历算法**。

下图是一个二叉搜索树例子：
![1.jpg](https://pic.leetcode-cn.com/08263672c434d95fa22498e21155a549298aafec5517a30f6410cee5c2726374-1.jpg)


我们用递归来做中序遍历，访问结点的顺序是 `4212346567` （这个序列就是 Morris 遍历得到的序列）。注意到非叶子结点 `246` 会被访问两次，第一次是作为根结点进入左子树，第二次是递归返回了，中序遍历到自己了。

那么不用递归或者栈，我们怎么在第二次成功返回根结点呢？注意到叶子结点的左右儿子都是空的，所以可以利用它们来指向根结点。

用结点 `4` 举个例子。首先访问 `4` ，然后遍历它的左子树。左子树的最后一个遍历的结点是 `3` ，那么我们就把 `3` 的右儿子指向根结点 `4` 。这样遍历完左子树之后，还能通过 `3` 的右儿子回到根结点 `4` ，接着继续遍历右子树。

所以在第一次访问根结点时，首先要找出它左子树中最右边的那个叶子结点，把它的右儿子指向根结点。然后才能放心地递归遍历左子树，不用担心回不去啦。

具体实现的时候还有一些细节，看代码更好理解，我都写在注释里面了。

## 代码
### c++
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = NULL, *y = NULL, *pre = NULL, *rightmost = NULL;
        while (root) {
            // 如果有左子树，就递归遍历左子树。
            if (root->left) {
                rightmost = root->left;
                // 找出左子树的最右边一个叶子结点
                while (rightmost->right && rightmost->right != root) {
                    rightmost = rightmost->right;
                }
                // 如果左子树最右边的叶子结点的右儿子是空的，
                // 那就说明根结点是第一次访问，那么就把它的右儿子指向根结点。
                // 然后递归遍历左子树。
                if (rightmost->right != root) {
                    rightmost->right = root;
                    root = root->left;
                // 否则的话说明根结点是第二次访问了，
                // 那就说明左子树已经递归完毕了，
                // 那么就判断一下是否存在逆序对。
                // 记得把左子树最右叶子结点的右儿子改回空指针。
                // 然后递归遍历右子树了。
                } else {
                    if (pre && pre->val > root->val) {
                        if (x == NULL) x = pre;
                        y = root;
                    }
                    rightmost->right = NULL;
                    pre = root;
                    root = root->right;
                }
            // 如果没有左子树，那就直接遍历右子树，同时判断是否存在逆序对。
            } else {
                if (pre && pre->val > root->val) {
                    if (x == NULL) x = pre;
                    y = root;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
```