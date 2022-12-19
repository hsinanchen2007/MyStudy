主要问题还是排序，就是遍历，然后按照和target差的绝对值排序，但是要保证这个排序不能太慢。
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

struct Node {
    int val;
    double target;
    bool operator<(const Node a) const { return abs(target - val) > abs(target - a.val); }
    Node(int v, double t) : val(v), target(t) {}
};

class Solution {
private:
    double target;
    
    priority_queue<Node> tmp;
    void dfs(TreeNode *p) {
        if (!p) return;
        dfs(p->left);
        tmp.push(Node(p->val, target));
        dfs(p->right);
    }
    
public:
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target;
        dfs(root);
        vector<int> res;
        for (int i = 0; i < k && !tmp.empty(); ++i) {
            auto j = tmp.top();
            res.push_back(j.val);
            tmp.pop();
        }
        return res;
    }
};
```
