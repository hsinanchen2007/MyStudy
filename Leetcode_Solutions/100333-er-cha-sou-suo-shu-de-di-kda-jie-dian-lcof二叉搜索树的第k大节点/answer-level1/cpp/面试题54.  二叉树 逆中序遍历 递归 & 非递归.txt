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

 //1. 迭代
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        
        stack< pair<TreeNode*, bool> > s;
        s.push(make_pair(root, false));
        TreeNode * node = NULL;
        bool visit;       
        while (!s.empty()) {
            node = s.top().first;
            visit = s.top().second;
            s.pop();
            if (node == NULL)
                continue;
            if (visit) {
                if (k == 1)
                    return node->val;
                k --;
            }
            else {
                s.push(make_pair(node->left, false));
                s.push(make_pair(node, true));
                s.push(make_pair(node->right, false));
            }
        }
        return 0;

    }
};


//2. 递归

// class Solution {
    
// private:
//     int val = 0;
//     // vector<int> res;

//     void find(TreeNode * & root, int &k) { // k用引用
//         if (root == NULL)
//             return;
//         find(root->right, k);
        
//         if (k == 1)
//             val = root->val;
//         k--;
//         // res.push_back(root->val);

//         find(root->left, k);
//     }


// public:
//     int kthLargest(TreeNode* root, int k) {

//         find(root, k);
//         return val;
//         // return res[k-1];
//     }
// };

```