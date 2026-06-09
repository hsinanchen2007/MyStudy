1. 根据根节点划分出左右子树（第一个大于根节点的值作为右子树根节点）
2. 右子树的每个值必须大于上一个根节点
3. 递归即可
```
class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        return preorder.size() < 2 || isPreorder(preorder, 0, preorder.size(), preorder[0], false);
    }

    bool isPreorder(vector<int> &preorder, int left, int right, int lastRoot, bool rightSub) {
        if (left >= right - 1) {
            return true;
        }
        int root = preorder[left];
        for (int i = left + 1; i < right; ++i) {
            if (rightSub && preorder[i] < lastRoot) {
                return false;
            }
            if (preorder[i] > root) {
                return isPreorder(preorder, left + 1, i, root, false) && isPreorder(preorder, i, right, root, true);
            }
        }
        return isPreorder(preorder, left + 1, right, root, false);
    }
};
```