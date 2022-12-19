### 代码
```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        """
        二叉搜索树中，左子树都比根小（小于等于），右子树都比跟大。
        在递归遍历的过程中，检查是否满足以上条件。

        测试点：
        []
        [1]
        [1,1]
        [1,1,2]
        [2,2,1]
        [1,6,3,2,5]
        [1,3,2,6,5]

        时间复杂度：O(n^2)
        空间复杂度：O(n)
        """
        # 没有元素也是二叉搜索树
        if not postorder:
            return True

        # 后续遍历中，最后一个元素便是树的根
        root = postorder[-1]

        # 为了便于后续处理，提前移除 root
        postorder = postorder[:len(postorder) - 1]

        # 二叉搜索树中，左子树都比根小
        # 因此第一个比根大的元素对应的索引就是 右子树第一个元素的索引
        i = 0
        while i < len(postorder) and postorder[i] <= root:
            i += 1

        # 右子树的元素应该都比 root 大
        j = i
        while j < len(postorder) and postorder[j] > root:
            j += 1
        if j != len(postorder):
            return False

        # 左、右子树也各有一个后续遍历，递归检查
        return self.verifyPostorder(postorder[:i]) and self.verifyPostorder(postorder[i:])

```