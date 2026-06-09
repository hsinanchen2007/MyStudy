
群友的题解
```
var inorderTraversal = function(root) {
    return root?
    [
      ...inorderTraversal(root.left),
      root.val,
      ...inorderTraversal(root.right)
    ]
    :[]
};
```
如果你自制力差，我来监督，这里有一群每天都在刷题的人，不刷题不进群。

关注公众号，回复算法，拉你进群。也可以查看每一期的算法思路

![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/cf56570eac6e1079e4cb624e669dea609f4b2229ae59eab7b7497d08ffe56286-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
