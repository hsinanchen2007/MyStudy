### 解题思路
1. 分析一下题目，可以得到信息：根节点肯定是第一个元素；对于左右子树来说，它们的根节点肯定在其他节点之前，但是两个子树之间的顺序是可以顺便混合的。
2. 通过以上信息，可以得到思路：在数组中插入第一个元素，查找左子树的所有结果，查找右子树的所有结果，之后保持左右两个数组自己的顺序不变的前提下，合并就可以了。
3. ex: root 2 left 0 1 right 3 4，可以是3 4 1 0，可以是0 3 1 4，需要保证的是0在1前，3在4前。所以，只要循环递归就行了。
4. PS：感觉这个问题，有点脱离实际。循环+递归，这个复杂度直接爆表啊，貌似是O(n!)？
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void merge(vector<int>& lVec, int i, vector<int>& rVec, int j, vector<int>& temp, vector<vector<int>>& res) {
        if (i == lVec.size() && j == rVec.size()) {
            res.push_back(temp);
            return;
        }

        if (i < lVec.size()) {
            temp.push_back(lVec[i]);
            merge(lVec, i+1, rVec, j, temp, res);
            temp.pop_back();
        }

        if (j < rVec.size()) {
            temp.push_back(rVec[j]);
            merge(lVec, i, rVec, j+1, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            res.push_back(vector<int>());
            return res;
        }

        vector<vector<int>> lVecs = BSTSequences(root->left);
        vector<vector<int>> rVecs = BSTSequences(root->right);
        vector<int> temp;
        temp.push_back(root->val);
        for (auto l : lVecs) {
            for (auto r : rVecs) {
                merge(l, 0, r, 0, temp, res);
            }
        }        
        return res;
    }
};
```