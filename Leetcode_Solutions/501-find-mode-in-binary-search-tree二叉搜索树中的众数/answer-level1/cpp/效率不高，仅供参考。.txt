```
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    vector<int> result;
    map<int, int> imap;
    void search(TreeNode* root) {
        if (!root) {
            return;
        }

        int val = root->val;
        if (imap.find(val) != imap.end()) {
            imap[val]++;
        } else {
            imap.insert(make_pair(val, 1));
        }
        search(root->left);
        search(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        search(root);
        if (imap.size() == 0) {
            return result;
        }
        vector<pair<int, int>> vec(imap.begin(), imap.end());
        //对线性的vector进行排序
        sort(vec.begin(), vec.end(), cmp);
        int count = vec[0].second;
        for (int i = 0; i < vec.size(); i++) {
            if (count == 1 && vec[i].second == 1) {
                result.push_back(vec[i].first);
            } else {
                if (count > 1 && count == vec[i].second) {
                    result.push_back(vec[i].first);
                }
            }
        }
        return result;
    }
};
```
