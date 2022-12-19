1. 先使用BuildMap函数构造HashMap,该表key：结点A, value：结点A父节点。帮助结点向上BFS
2. LocateTarget函数：用于找到val=k的目标结点target
3. 从target为起点，进行BFS，遇到的第一个叶子节点就是答案
    - BFS左子树
    - BFS右子树
    - BFS父节点
需要注意的是：防环：构造set<TreeNode*>parent: 记录遍历的路径，防止重复遍历

该题解目前是最佳解法，比其他构建邻接矩阵方法好很多：
```
力扣通过记录：
执行结果：通过
执行用时 :16 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :17.8 MB, 在所有 C++ 提交中击败了100.00%的用户
```

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
    int findClosestLeaf(TreeNode* root, int k) {
        map<TreeNode*, TreeNode*> GM;
        vector<TreeNode*> Leaves;
        TreeNode* target = LocateTarget(root, k);
        //cout<<target<<" "<<target->val<<endl;
        set<TreeNode*> parent={target};
        BuildMap(root, GM);
        /*
        for(auto it=GM.begin(); it!=GM.end(); it++)
            cout<<it->first->val<<" "<<it->second->val<<endl;
        */
        return bfs(target, GM, parent);
    }
private:
    int bfs(TreeNode* root, map<TreeNode*, TreeNode*>& GM, set<TreeNode*>parent){
        queue<TreeNode*> path;
        path.push(root);
        while(!path.empty()){
            for(int i=0; i<path.size(); i++){
                TreeNode* tmp = path.front();
                parent.insert(tmp);
                path.pop();
                // tree
                if(tmp->left==nullptr & tmp->right==nullptr) {
                    return tmp->val;
                }
                if(tmp->left!=nullptr & parent.find(tmp->left)==parent.end()) {
                    path.push(tmp->left);
                    parent.insert(tmp->left);
                }
                if(tmp->right!=nullptr & parent.find(tmp->right)==parent.end()) {
                    path.push(tmp->right);
                    parent.insert(tmp->right);
                }
                // hashmap
                if(GM.count(tmp)!=0 & parent.find(GM[tmp])==parent.end()) {
                    path.push(GM[tmp]);
                    parent.insert(GM[tmp]);
                }
            }
            
        }
        return -1;
    }
    
    void BuildMap(TreeNode* root, map<TreeNode*, TreeNode*>& GM){
        if(!root) return;
        if(root->left) {
            GM[root->left] = root;
            BuildMap(root->left, GM);
        }
        if(root->right) {
            GM[root->right] = root;
            BuildMap(root->right, GM);
        }
    }
    
    TreeNode* LocateTarget(TreeNode* root, int k){
        queue<TreeNode*> path;
        path.push(root);
        while(!path.empty()){
            for(int i=0; i<path.size(); i++){
                TreeNode* tmp = path.front();
                if(tmp->val == k) return tmp;
                path.pop();
                if(tmp->left) path.push(tmp->left);
                if(tmp->right) path.push(tmp->right);
            }
        }
        
        return nullptr;
    }
};
```