### 解题思路
此处撰写解题思路

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>vec;
        if(n==0)return vec;
        int start=1;
        int end=n;
        return help(start,end);
        
    }
    vector<TreeNode*>help(int start,int end){
        vector<TreeNode*>vec;
        if(start>end){
            TreeNode* l=NULL;
            vec.push_back(l);
            return vec;
        }
        else{
            vector<TreeNode*>vec;
            for(int i=start;i<=end;i++){
                vector<TreeNode*>lf=help(start,i-1);
                vector<TreeNode*>ri=help(i+1,end);
                for(int x=0;x<lf.size();x++){
                    for(int y=0;y<ri.size();y++){
                        auto tree=new TreeNode(i);
                        tree->left=lf[x];
                        tree->right=ri[y];
                        vec.push_back(tree);
                    }
                }
            }
            return vec;
        }
    }
};
```