![200.png](https://pic.leetcode-cn.com/d84c35da2f62a535ad5109ad5a68746ade376eb855c2198dcae8b72def1fca89-200.png)
### 解题思路
在题目没有重复数字的前提下，二叉搜索树的左子树均小于根节点，右子树均大于根节点。
判断二叉搜索树的后续遍历是否合法，只需判断右子树是否均大于根节点，左子树是否均小于根节点。
显然对于每个节点的操作都是一样的(问题拆解成子问题))，所以使用递归来实现。

### 代码

```javascript
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function (postorder) {
    let len = postorder.length;
    // 若为叶子节点，则返回 true
    if (len < 2) return true
    // 后序遍历的最后一个元素为根节点
    let root = postorder[len - 1];
    let i = 0
    // 划分左/右子树
    for (; i < len - 1; i++) {
        if (postorder[i] > root) break
    }
    // 判断右子树中的元素是否都大于 root，此处用到 every (数组 API，数组的每个元素都返回 true 则整体返回 true)
    let result = postorder.slice(i, len - 1).every(x => x > root);
    if (result) {
        // 对左右子树进行递归调用,左右子树通过 i 进行分割
        return verifyPostorder(postorder.slice(0, i)) && verifyPostorder(postorder.slice(i, len - 1))
    } else {
        return false
    }
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/6118320784c4beb9786e887eece3dacd88309a4d0d19f76ebd3a09078d2fc333-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
