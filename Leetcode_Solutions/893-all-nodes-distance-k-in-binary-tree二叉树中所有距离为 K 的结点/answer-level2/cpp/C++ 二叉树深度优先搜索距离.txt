- 1. 用哈希表保存每个结点父节点
- 2. 对target按自定义规则深度优先遍历
    + 1. 如果结点是父节点,需要进入非target祖先结点的子树，并通过哈希表进入父节点
    + 2. 如果不是，则普通DFS

```C++
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        // 制作倒树map
        map<TreeNode*,TreeNode*> resTree;
        dfs(root, resTree);
        /*
        cout<<"map tree"<<endl;
        for(auto it=resTree.begin(); it!=resTree.end(); it++)
            cout<<it->first->val<<" "<<it->second->val<<endl;
        */
        // 标记target父节点
        // dfs map即可：结点不在set,按树遍历，在set,按map和树遍历
        set<TreeNode*> parent = {target};
        TreeNode* tmp = target;
        //dfstree(target, 0, K, result);
        int dist=0;
        dfstree(tmp, dist, K, parent,result);
        dist++;
        while(resTree.count(tmp)){
            parent.insert(resTree[tmp]);
            tmp = resTree[tmp];
            //cout<<tmp->val<<','<<dist<<endl;
            dfstree(tmp, dist, K, parent, result);
            dist++;
        }
        return result;
}
private:
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*>& resTree){
        if(!root) return;
        if(root->left){
            resTree[root->left] = root;
            dfs(root->left, resTree);
        }
        if(root->right){
            resTree[root->right]= root;
            dfs(root->right, resTree);
        }
    }
    void dfstree(TreeNode* root, int n, int K, set<TreeNode*> parent,vector<int>& result){
        if(!root || n>K) return;
        //cout<<"dfs "<<root->val<<endl;
        if(n==K){
            result.push_back(root->val);
            return;
        }
        if(root->left && parent.find(root->left)==parent.end())
            dfstree(root->left, n+1, K, parent, result);
        if(root->right && parent.find(root->right)==parent.end())
            dfstree(root->right, n+1, K, parent, result);
        return;
    }
    

    
};
```