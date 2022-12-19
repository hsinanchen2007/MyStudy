### 前言

层次遍历又称广度优先遍历，因此，此题可视为练习经典广度优先搜索算法的典范。故记之。
### 广度优先遍历思想
广度优先遍历算法思想为从根节点开始，每次遍历当前节点的所有兄弟节点(包括表兄)后，再进入子节点。即按层遍历。
### 广度优先遍历实现
1. 将根节点加入队列`queue`
2. 如果队列`queue`不为空：重复步骤2-6
3. 获取当前队列长度，即当前层兄弟节点个数`nums`
4. `for index in range(1,nums):` 从队列弹出首个节点`q_front`,并存入层列表`tmp`中；将`q_front`的左右非空子节点加入队列`queue`中
5. 将层列表压入结果`ans`
6. 清空层列表`tmp ` 
6. 输出结果`ans`

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
    vector<vector<int>> levelOrder(TreeNode* root) {       
        queue<TreeNode*> q;
        TreeNode* q_front;
        vector<vector<int>> ans;
        vector<int> tmp;
        int nums;

        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            nums=q.size();
            for(int i=1;i<=nums;i++){
                q_front=q.front();
                tmp.push_back(q_front->val);
                q.pop();
                if(q_front->left!=NULL)
                    q.push(q_front->left);
                if(q_front->right!=NULL)
                    q.push(q_front->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
```