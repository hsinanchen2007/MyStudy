此题目和[106. 从后序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/si-lu-qing-xi-dai-ma-jian-ji-he-105ti-si-lu-yi-zhi/) 和 [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/si-lu-qing-xi-dai-ma-jian-ji-he-105ti-si-lu-yi-z-2/) 完全一致，如果你会其中一个，那么其他也一定会。

我们以题目给出的测试用例来讲解：
![](https://pic.leetcode-cn.com/584db66158d2b497b9fdd69b5dc10c3a76db6e2c0f6cff68789cfb79807b0756.jpg)

前序遍历是`根左右`，因此preorder第一个元素一定整个树的根，preorder第二个元素（如果存在的话）一定是左子树。由于题目说明了没有重复元素，因此我们可以通过val去postorder找到pre[1]在postorder中的索引i。
而由于后序遍历是`左右根`，因此我们容易得出。  postorder 中的0到i(包含)是左子树，preorder的1到i+1（包含）也是左子树。

具体思路可以参考上面两题。

代码：

```python
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        if not pre:
            return None
        node = TreeNode(pre[0])
        if len(pre) == 1:
            return node
        i = post.index(pre[1])

        node.left = self.constructFromPrePost(pre[1:i + 2], post[:i + 1])
        node.right = self.constructFromPrePost(pre[i + 2:], post[i + 1:-1])

        return node
```


**复杂度分析**

- 时间复杂度：由于每次递归我们的postorder和preorder的总数都会减1，因此我们要递归N次，故时间复杂度为 $O(N)$，其中N为节点个数。
- 空间复杂度：我们使用了递归，也就是借助了额外的栈空间来完成， 由于栈的深度为N，因此总的空间复杂度为 $O(N)$，其中N为节点个数。

> 空间复杂度忽略了开辟数组的内存消耗。


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)