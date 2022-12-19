### 解题思路
1、思路是按广度把每一层的结点存进数组，最后进行反转；
2、二维数组result存放不断更新的结果数组，数组result_index存放每一层的所有结点，并在遍历完一层节点后存放进result；
3、两个队列，队列q存放当前遍历层，队列q_index存放当前遍历层的下一层；
4、while循环的结束条件是队列q为空，即全部结点已遍历；
5、每当遍历完一层结点----队列q会变空，这时开始遍历下一层----检查队列q_index，若其中还有结点，全部放入队列q中，即下一层为当前遍历层。

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
    
        if(!root) return result;

        vector<int> result_index;
        queue<TreeNode*> q;
        queue<TreeNode*> q_index;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            result_index.push_back(p->val);

            if(p->left) q_index.push(p->left);
            if(p->right) q_index.push(p->right);

            if(q.empty()) 
            {
                while(!q_index.empty())
                {
                    q.push(q_index.front());
                    q_index.pop();
                }
                result.push_back(result_index);
                result_index.clear();
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```