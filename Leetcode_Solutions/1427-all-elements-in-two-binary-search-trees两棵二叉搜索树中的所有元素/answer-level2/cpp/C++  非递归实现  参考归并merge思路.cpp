### 解题思路
![截屏2019-12-29下午1.26.55.png](https://pic.leetcode-cn.com/c069c1ff2336fbd48ef8753bc5cda0ff5035d4c00af02c7e1fc49c1e3950d856-%E6%88%AA%E5%B1%8F2019-12-29%E4%B8%8B%E5%8D%881.26.55.png)
参考归并排序 merge 部分的思路
时间复杂度 O(N)
空间复杂度 O(N)

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<TreeNode*> l,r;
        TreeNode* cur1 = root1;
        TreeNode* cur2 = root2;
        while (cur1 || cur2 || !l.empty() || !r.empty()) {
            while (cur1) {
                l.push(cur1);
                cur1 = cur1->left;
            }
            while (cur2) {
                r.push(cur2);
                cur2 = cur2->left;
            }
            if (r.empty() || (!l.empty() && !r.empty() && l.top()->val <= r.top()->val)){
                cur1 = l.top();
                l.pop();
                result.push_back(cur1->val);
                cur1 = cur1->right;
            } else {
                cur2 = r.top();
                r.pop();
                result.push_back(cur2->val);
                cur2 = cur2->right;
            }
        }
        return result;
    }
};
```