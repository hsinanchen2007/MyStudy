提供一种思路，先中序遍历得到节点指针顺序存到vector中，再来转换就简单很多了，缺点就是会消耗空间
```
class Solution {
public:
    vector<Node*> vec;
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        dfs(root);
        int n = vec.size();
        //for(auto& item:vec) cout<<item->val<<endl;
        for(int i=0;i<n-1;i++){
            vec[i]->right = vec[i+1];
        }
        for(int i=n-1;i>0;i--){
            vec[i]->left = vec[i-1];
        }
        vec[0]->left = vec[n-1];
        vec[n-1]->right = vec[0];
        return vec[0];
    }
    void dfs(Node* root){
        if(root==NULL)return;
        dfs(root->left);
        vec.push_back(root);
        dfs(root->right);
    }
};
```
