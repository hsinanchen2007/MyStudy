### 解题思路
方法就是通过树的层次遍历，并且在遍历过程中每一个层级用一个哈希表记录该层出现的值，该哈希表的key是该层节点的值，其value存储父节点的值

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            int n=q.size();
            unordered_map<int,int> hash;
            for(int i=0;i<n;i++){
                auto pr=q.front();
                q.pop();
                TreeNode *t=pr.first;
                if(t->left)q.push({t->left,t->val});
                if(t->right)q.push({t->right,t->val});
                hash.insert(make_pair(t->val,pr.second));
            }
            if(hash.find(x)!=hash.end()&&hash.find(y)!=hash.end()&&hash[x]!=hash[y])return true;
        }
        return false;
    }
};
```