### 解题思路
钻了所有节点都是正整数的空子，用0表示空节点，一个前序遍历存起来，看两个是否相同。

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
    void preo(TreeNode* p, vector<int> &v){
        if(p) {
            v.push_back(p->val);
            preo(p->left, v);
            preo(p->right, v);
        }else{
            v.push_back(0);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ppre,qpre;
        preo(p, ppre);
        preo(q, qpre);
        if(ppre.size() == qpre.size()){
            for(int i = 0; i < qpre.size(); i++){
                if(ppre[i] != qpre[i]){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
};
```