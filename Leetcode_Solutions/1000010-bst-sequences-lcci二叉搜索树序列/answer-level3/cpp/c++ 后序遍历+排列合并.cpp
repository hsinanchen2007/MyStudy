算法分为两块：
1. 使用后序遍历，在根节点视角将左右子节点的数组进行两两组合。
2. 左右子节点数组两两组合不能改变数组内元素顺序，而左右数组元素的顺序可以乱序，因此存在从左数组取元素和从右数组取元素的情况，两个数组取完就能得到一个完整序列。
时间复杂度：遍历n个节点，每个节点作为根合并左右节点数组需要n!,因此最坏时间复杂度为O(n*n!)
```
class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        return post_order(root);
    }
    vector<vector<int>> post_order(TreeNode* root) {
        if (!root) {
            return {{}};
        }

        auto lv = post_order(root->left);
        auto rv = post_order(root->right);
        vector<vector<int>> res;
        if (lv.size() == 0) {
            for (auto& r: rv) {
                vector<int> cur = {root->val};
                cur.insert(cur.end(), r.begin(), r.end());
                res.push_back(cur);
            }
            return res;
        }
        if (rv.size() == 0) {
            for (auto& l: lv) {
                vector<int> cur = {root->val};
                cur.insert(cur.end(), l.begin(), l.end());
                res.push_back(cur);
            }
            return res;
        }
        for (int i = 0; i < lv.size(); i++) {
            for (int j = 0; j < rv.size(); j++) {
                vector<int> cur = {root->val};
                merge(lv[i], 0, rv[j], 0, cur, res);
            }
        }
        return res;
    }

    void merge(vector<int>& l, int li, vector<int>& r, int ri, 
        vector<int>& cur, vector<vector<int>>&res) {
        if (li == l.size() && ri == r.size()) { // 两个数组取完了
            res.push_back(cur);
            return;
        }
        if (li < l.size()) { // 左数组取一个元素
            cur.push_back(l[li]);
            merge(l, li+1, r, ri, cur, res);
            cur.pop_back();
        }
        if (ri < r.size()) {
            cur.push_back(r[ri]);
            merge(l, li, r, ri+1, cur, res);
            cur.pop_back();
        }
    }
};
```
