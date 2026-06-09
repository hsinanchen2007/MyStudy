这题看了，就感觉用回溯。
为啥我的回溯条件写在dfs函数中间呢，我才开始写的是下面的回溯条件，结果产生了重复值,因为会遍历叶子节点的左右结点各一次，造成结果重复。
```
if(root==NULL && tmpsum==sum)
```
源代码：
```
vector<int> tmpans;
    vector<vector<int>> ans;
    int tmpsum=0;
    void dfs(TreeNode* root,int & sum)
    {
        tmpsum+=root->val;
        tmpans.push_back(root->val);
        if(root->left!=NULL)
            dfs(root->left,sum);
        if(root->right!=NULL)
            dfs(root->right,sum);
        if(root->left==NULL && root->right==NULL && tmpsum==sum)
        {
            ans.push_back(tmpans);
            tmpsum-=root->val;
            tmpans.pop_back();
            return;
        }
        tmpsum-=root->val;
        tmpans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return ans;
        dfs(root,sum);
        return ans;
    }
```
