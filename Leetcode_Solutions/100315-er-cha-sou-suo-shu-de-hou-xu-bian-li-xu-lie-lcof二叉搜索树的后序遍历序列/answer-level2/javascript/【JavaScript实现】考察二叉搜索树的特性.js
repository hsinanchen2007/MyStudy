
## 思路

这题主要考察的是后序遍历的特点和二叉搜索树的特点。根据定义，后序遍历结果的最后一个元素就是当前二叉树的根元素。结合二叉搜索树 左子节点 > 根节点 > 右子节点 的特点，我们可以找到左右子树的元素。

例如下面这个二叉搜索树：

![](https://pic.leetcode-cn.com/cf9ccec7dda9620301a975355f6b8bbca91c6cc13d776027579a2a37ce5d951c.jpg)

它的后序遍历顺序是：2，7，9，12，11，8。所以整体的解决思路是：

-   最后一个元素是根节点：8
-   因为左子树都小于根节点，从头开始遍历可以找到左子树：2、7。
-   剩下的元素就是右子树：9、12、11。
-   再分别递归检查左右子树是否满足后序遍历顺序

## 代码实现

```javascript
/**
 * @param {number[]} sequence
 * @return {boolean}
 */
function verifyPostorder(sequence) {
    const length = sequence.length;
    if (length < 2) return true;

    const root = sequence[length - 1];
    // sequence[0, root) 是左子树；sequence[root, length - 1)是右子树
    let cut = 0; // 左子树节点的数量
    for (; cut < length - 1 && sequence[cut] < root; ++cut) {}
    // 这里要检查右子树中的值是否满足条件
    for (let i = cut; i < length - 1; ++i) {
        if (sequence[i] < root) {
            return false;
        }
    }

    return (
        verifyPostorder(sequence.slice(0, cut)) &&
        verifyPostorder(sequence.slice(cut, length - cut - 1))
    );
}
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
