- 递归很简单，关键是怎么实现非递归，我一般利用栈来实现非递归遍历。
- 这里要求中序遍历，即先遍历左子树，再遍历根节点，最后遍历右子树。
- 一直寻找左节点，每次的节点都压栈，直到某个节点p没有左节点了为止，然后**将p出栈**，遍历p，然后看p是否有右节点，如果有那么将右节点压**一个**入栈，将最上面的元素出栈。
- 重复上述步骤即可。
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode* p=root;
        while(!s.empty()){
            if(p==NULL) break;
            while(p->left){//将所有左节点都入栈
                p=root->left;
                root->left=NULL;
                root=p;
                s.push(p);
            }
            ans.push_back(p->val);
            s.pop();
            if(p->right){//注意这里只压一个右节点入栈
                p=root->right;
                root->right=NULL;
                root=p;
                s.push(p);
            }
            if(s.empty()) break;
            p=s.top();
            root=p;
        }
        return ans;
    }
};
```
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        vector<int>l;
        vector<int>r;
        if(root->left) l=inorderTraversal(root->left);
        if(root->right) r=inorderTraversal(root->right);
        for(int i=0;i<l.size();i++){
            ans.push_back(l[i]);
        }
        ans.push_back(root->val);
        for(int i=0;i<r.size();i++){
            ans.push_back(r[i]);
        }
        return ans;
    }
};
```
