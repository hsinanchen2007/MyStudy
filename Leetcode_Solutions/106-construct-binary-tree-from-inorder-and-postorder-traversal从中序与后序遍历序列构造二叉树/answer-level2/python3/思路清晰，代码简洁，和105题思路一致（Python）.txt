此题目和[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/si-lu-qing-xi-dai-ma-jian-ji-he-105ti-si-lu-yi-z-2/) 完全一致，如果你会其中一个，那么另外一个也一定会。

我们以题目给出的测试用例来讲解：
![](https://pic.leetcode-cn.com/fb9d700a67d70b5e68461fa1f0438d9c5c676557a776eda4cd1b196c41ce65a1.jpg)

后序遍历是`左右根`，因此postorder最后一个元素一定整个树的根。由于题目说明了没有重复元素，因此我们可以通过val去inorder找到根在inorder中的索引i。
而由于中序遍历是`左根右`，我们容易找到i左边的都是左子树，i右边都是右子树。

我使用红色表示根，蓝色表示左子树，绿色表示右子树。

![](https://pic.leetcode-cn.com/10176eec270c90d8e0bd4640a628e9320b7d5c30f3c62ffdb1fd2800d87c6f7b.jpg)

根据此时的信息，我们能构造的树是这样的：

![](https://pic.leetcode-cn.com/261696c859c562ca31dface08d3020bcd20362ab2205d614473cca02b1635eb0.jpg)

其中右子树由于个数大于1，我们无法确定，我们继续执行上述逻辑。我们postorder继续向前移动一位，这个时候我们得到了第二个根节点”20“，实际上就是右子树的根节点。

![](https://pic.leetcode-cn.com/e6cac2b6a956c09d977c4cfd7883268644b42bdd0531a509d24b4aafebc147c4.jpg)

根据此时的信息，我们能构造的树是这样的：


![](https://pic.leetcode-cn.com/f8553f668bed9f897f393a24d78e4469c4b5503c4ba8c59e90dca1b19acf4de5.jpg)


我们不断执行上述逻辑即可。简单起见，递归的时候每次我都开辟了新的数组，这个其实是没有必要的，我们可以通过四个变量来记录inorder和postorder的起始位置即可。


代码：

```python
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        # 实际上inorder 和 postorder一定是同时为空的，因此你无论判断哪个都行
        if not inorder:
            return None
        root = TreeNode(postorder[-1])
        i = inorder.index(root.val)
        root.left = self.buildTree(inorder[:i], postorder[:i])
        root.right = self.buildTree(inorder[i+1:], postorder[i:-1])

        return root
```


**复杂度分析**

- 时间复杂度：由于每次递归我们的inorder和postorder的总数都会减1，因此我们要递归N次，故时间复杂度为 $O(N)$，其中N为节点个数。
- 空间复杂度：我们使用了递归，也就是借助了额外的栈空间来完成， 由于栈的深度为N，因此总的空间复杂度为 $O(N)$，其中N为节点个数。

> 空间复杂度忽略了开辟数组的内存消耗。


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)