执行用时 :8 ms, 在所有 C++ 提交中击败了74.08%的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了98.96%的用户

```
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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        map<TreeNode*, string> paths;//地图用来保存节点与根的路径关系
        
        stack<TreeNode*> tree;//栈用来临时保存探索过的节点
        
        vector<string> output;//输出
        
        if(root==NULL)
            return output;
        
        
        tree.push(root);

        paths[tree.top()] = to_string(tree.top()->val);//先把根节点和路径起点丢到地图里
        
        while(!tree.empty()){
            
            TreeNode* node = tree.top();
            tree.pop();
            
            if(node->left!=NULL){//如果当前节点左子不为空，则把根到当前节点左子的路径在地图里更新
                tree.push(node->left);
                paths[node->left] += (paths[node] + "->" + to_string(node->left->val));
            }
                
            if(node->right!=NULL){//如果当前节点右子不为空，则把根到当前节点右子的路径在地图里更新
                tree.push(node->right);
                paths[node->right] += (paths[node] + "->" + to_string(node->right->val));
            }
            if(node->left==NULL && node->right==NULL){//如果当前节点左右子都为空，则说明已经探索到叶了，输出到答案里
                output.push_back(paths[node]);
                
            }
                
        }
        
        return output;
    }
};
```
