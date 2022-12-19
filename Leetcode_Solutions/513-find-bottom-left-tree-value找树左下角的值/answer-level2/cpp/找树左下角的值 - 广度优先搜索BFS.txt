### 解题思路
1. 定义一个队列，同时存节点及对应的深度，初始时将树根节点及深度0加入队列
2. 弹出队列首元素，判断它的深度是否比当前记录的最大深度还大。若是，说明达到了树的下一层。更新作为左下角备选值的`ans`
3. 若该首元素有左孩子，将其左孩子和其对应深度加入到队列中，若有右孩子做同样处理
4. 循环执行步骤`3.`，直到队空，`ans`即为所求

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
    int findBottomLeftValue(TreeNode* root) {
        int h = -1, ans;
        queue<pair<TreeNode *, int>> tq;
        tq.push({root, 0});
        while(!tq.empty()){
            auto pr = tq.front(); tq.pop();
            TreeNode* tmp_root = pr.first;
            int tmp_val = pr.second;
            if(tmp_val > h){
                ans = tmp_root->val;
                h = tmp_val;
            }
            if(tmp_root->left){
                tq.push({tmp_root->left, tmp_val+1});
            }
            if(tmp_root->right){
                tq.push({tmp_root->right, tmp_val+1});
            }
        }
        return ans;        
    }
};
```