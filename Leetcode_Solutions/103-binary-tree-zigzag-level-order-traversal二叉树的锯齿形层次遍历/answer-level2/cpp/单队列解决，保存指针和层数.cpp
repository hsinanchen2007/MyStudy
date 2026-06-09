用了双向队列保存。
依靠层数判断是否要倒着读还是顺着读，可能因为push_back的有点多，所以有点慢。
比如从front开始取的时候，push就到back，然后front已经是下一层的了，就要翻转了。
翻转之后从back开始取，push到front，到back已经是下一层的时候，就正着读。
再用层数当下标，push到result数组里就好了，前面加一个判断，result数组空间不足时，加一层。

```
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<pair<TreeNode*, int>> tmp;
        vector<vector<int>> res;
        bool flag = 1;
        if (root) tmp.push_back({root, 0});
        int c = 0;
        TreeNode *p;
        while (!tmp.empty()) {
            if (flag) {
                p = tmp.front().first;
                c = tmp.front().second;
                tmp.pop_front();
                if (p->left) tmp.push_back({p->left, c + 1});
                if (p->right) tmp.push_back({p->right, c + 1});
                if (!tmp.empty() && tmp.front().second == c + 1) flag = !flag;
            } else {
                p = tmp.back().first;
                c = tmp.back().second;
                tmp.pop_back();
                if (p->right) tmp.push_front({p->right, c + 1});
                if (p->left) tmp.push_front({p->left, c + 1});
                if (!tmp.empty() && tmp.back().second == c + 1) flag = !flag;
            }
            if (res.size() < c + 1) res.push_back({});
            res[c].push_back(p->val);
        }
        return res;
    }
};
```