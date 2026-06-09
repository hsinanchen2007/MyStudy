### 解题思路
- 回溯法
    - 用track来动态保存当前进行的位置，如果符合了条件（叶子节点，且和满足），就将此时的track放入ans；否则的话，继续向下查找。若最后左右均找完了后，将此节点从track中拿出，返回上一层。回溯！

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> track;
        vector<vector<int> > ans;
        if(root==NULL)  {};
        backTrack(root,ans,track,sum);
        return ans;
    }

    void backTrack(TreeNode*t,vector<vector<int> >&ans,vector<int>&track,int sum){
        if(t==NULL)  return;
        track.push_back(t->val);
        sum-=t->val;
        if(sum==0&&t->left==NULL&&t->right==NULL){
            ans.push_back(track);
        }
        if(t->left){
            backTrack(t->left,ans,track,sum);
        }
        if(t->right){
            backTrack(t->right,ans,track,sum);
        }
        sum+=t->val; //不加也可，但是会慢很多。为什么？
        track.pop_back();
    }
    
};
```