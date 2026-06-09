### 深度优先搜索 ###
#### 思路 ####
- 同时对 $original$ 和 $cloned$ 进行深度优先搜索，$original$ 为空时返回空指针
  - 当 $original$ 与 $target$ 指向同一节点时，返回 $cloned$
  - 否则，搜索 $original$ 的左子树，$cloned$ 的指针也同时指向其左子树
    - 若左子树的搜索结果不为空，则说明找到了 $target$，否则按上述方法搜索右子树
#### 代码 ####
```cpp []
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        return left ? left : getTargetCopy(original->right, cloned->right, target);
    }
};
```
```python3 []
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if not original: return None
        if original is target: return cloned
        left = self.getTargetCopy(original.left, cloned.left, target)
        return left if left else self.getTargetCopy(original.right, cloned.right, target)
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$
- 空间复杂度 $O(n)$
