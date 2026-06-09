### 解题思路
双向队列，根据层数的奇偶进行不同操作

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        deque<TreeNode *>dq;
        vector<int>temp;
        dq.push_back(root);
        int cengshu=1;
        int cnt=1;
        while(!dq.empty()){
            TreeNode *tempN;
            if(cengshu%2==0){
                tempN=dq.front();
                dq.pop_front();
                cnt--;
                if(tempN->right){
                    dq.push_back(tempN->right);
                }
                if(tempN->left){
                    dq.push_back(tempN->left);
                } 
            }else{
                tempN=dq.back();
                dq.pop_back();
                cnt--;
                if(tempN->left){
                    dq.push_front(tempN->left);
                }
                if(tempN->right){
                    dq.push_front(tempN->right);
                }
            }
            if(cnt>0){
                temp.push_back(tempN->val);
            }else{
                temp.push_back(tempN->val);
                cnt=dq.size();
                ans.push_back(temp);
                temp.clear();
                cengshu++;
            }
        }
    return ans;
    }
};
```