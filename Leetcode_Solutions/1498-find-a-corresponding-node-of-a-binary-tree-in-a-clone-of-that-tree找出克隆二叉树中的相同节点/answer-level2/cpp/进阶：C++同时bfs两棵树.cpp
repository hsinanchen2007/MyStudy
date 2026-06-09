### 解题思路
同时遍历两棵树，当源树遇到目标结点时，克隆树一定也遇到了需要返回的相同结点，与target的值无关。

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode *> qu1, qu2;
        int cnt = 0;
        qu1.push(original);
        qu2.push(cloned);
        while(!qu1.empty()){
            int n = qu1.size();
            for(int i = 0; i < n; i++){
                TreeNode *p1 = qu1.front(); qu1.pop();
                TreeNode *p2 = qu2.front(); qu2.pop();
                if(p1 == target) return p2;
                if(p1->left){
                    qu1.push(p1->left);
                    qu2.push(p2->left);
                }
                if(p1->right){
                    qu1.push(p1->right);
                    qu2.push(p2->right);
                }
            }
        }
        return nullptr;
    }
};
```