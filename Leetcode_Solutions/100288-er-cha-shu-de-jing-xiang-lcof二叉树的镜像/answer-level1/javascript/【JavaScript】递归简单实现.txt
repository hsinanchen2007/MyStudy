
搞清楚镜像的定义，简单来说就是：从上到下，依次交换每个节点的左右节点。

来自《剑指 Offer》的示意图：
![](https://pic.leetcode-cn.com/0f4a336f536d7bcb4c6d06c2ca72e0ff7505e269b9121689e2dc10aa4dd3c7cf.jpg)

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
// 原文地址：https://xxoo521.com/2020-01-13-tree-jing-xiang/

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if (!root) {
        return null;
    }
    // 交换当前节点的左右节点
    const leftCopy = root.left;
    root.left = root.right;
    root.right = leftCopy;

    // 对左右子树做相同操作
    mirrorTree(root.left);
    mirrorTree(root.right);

    return root;
};
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
