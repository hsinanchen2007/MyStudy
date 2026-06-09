
## 题目分析

本题考察二叉搜索树的性质：`左节点 < 当前节点 < 右节点`。转换后的双向链表是有序的，这里采用中序递归遍历保证有序性。

题目要求循环双向链表，因此尾节点的 right 要指向首节点，首节点的 left 要指向尾节点。

## 解法 1: 递归+中序遍历

结合中序遍历，递归处理二叉树。初始化一个代表上一个节点的 pre 变量。递归中要做的就是：pre 的 right 指针指向当前节点 node，node 的 left 指向 pre，并且将 pre 更新为 node。

要注意的是，当递归到最下面的左节点时，pre 为空，要保留节点作为循环链表的 head。并在中序遍历结束后，处理头节点和尾节点的指针关系。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
// 原文地址：https://xxoo521.com/2020-02-06-btree-link/

/**
 * @param {Node} root
 * @return {Node}
 */
var treeToDoublyList = function(root) {
    if (!root) {
        return;
    }
    let head = null;
    let pre = head;
    inorder(root);
    // 完成中序遍历后，pre指向了最后一个节点
    // 将其闭合成环状结构
    head.left = pre;
    pre.right = head;
    return head;

    /**
     * @param {Node} node
     */
    function inorder(node) {
        if (!node) return;
        // 遍历左子树
        inorder(node.left, pre);

        // 处理当前节点
        if (!pre) {
            // 遍历到最左边节点，此时节点就是双向链表的head
            head = node;
        } else {
            pre.right = node;
        }
        node.left = pre;
        pre = node;

        // 遍历右子树
        inorder(node.right, pre);
    }
};
```

整个过程的要递归遍历一遍二叉树，时间复杂度是 O(N)，空间复杂度是 O(N)。

## 解法 2: 非递归+中序遍历

这里可以将递归转换为非递归的的中序遍历。转化思路是用栈来模拟递归调用的过程，其他的处理和解法 1 一样。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
// 原文地址：https://xxoo521.com/2020-02-06-btree-link/
/**
 * @param {Node} root
 * @return {Node}
 */
var treeToDoublyList = function(root) {
    if (!root) {
        return;
    }

    const stack = [];
    let node = root;
    let pre = null;
    let head = null;
    while (stack.length || node) {
        if (node) {
            stack.push(node);
            node = node.left;
        } else {
            const top = stack.pop();
            if (!pre) {
                head = top;
            } else {
                pre.right = top;
            }
            top.left = pre;
            pre = top;

            node = top.right;
        }
    }

    head.left = pre;
    pre.right = head;
    return head;
};
```

关于前序、中序和后序的非递归写法可以参考这篇文章：[《二叉树前序、中序、后序遍历非递归写法的透彻解析》](https://blog.csdn.net/zhangxiangDavaid/article/details/37115355)。这里不再多说。

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
