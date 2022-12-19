### 解题思路
joshua分享：把二叉树转换成一个图的结构，然后从terget开始深度遍历即可

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<vector<int>> net(501, vector<int>());
        vector<bool> isVisit(501, false);
        vector<int> ans;
        queue<int> q;
        int level = 0;

        if(K == 0) return vector<int>(1, target->val);

        getNet(root, net);

        /*
        cout << "begin" << endl;
       
        cout << "end" << endl;
        for( int i = 0; i < 10; i++) {
            cout<<i<<": ";
            for(int j = 0; j <net[i].size(); j++) {
                cout << net[i][j] << ", ";
            }
            cout << endl;
        }
        */

        q.push(target->val);
        isVisit[target->val] = true;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int cur = q.front();
                q.pop();

                for(int j = 0; j < net[cur].size(); j++) {
                    if(isVisit[ net[cur][j] ]) continue;
                    isVisit[ net[cur][j] ] = true;
                    q.push( net[cur][j] );
                }
            }
            level++;
            if(level == K) break;
        }

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    void getNet(TreeNode* root, vector<vector<int>> &net) {
        if(!root) return;
        if(root->left) {
            net[root->val].push_back(root->left->val);
            net[root->left->val].push_back(root->val);
            getNet(root->left, net);
        }
        if(root->right) {
            net[root->val].push_back(root->right->val);
            net[root->right->val].push_back(root->val);
            getNet(root->right, net);
        }
    }
};
```