### 解题思路
遍历，使用map来记录层数和这一层的节点数量，最后计算平均数

### 代码 dfs

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
    map<int,int> m_num;
    map<int,double> m_sum;
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        vector<double> res;

        for(int i=0;i<m_num.size();i++){
            res.push_back(m_sum[i]/m_num[i]);
        }
        return res;
    }
    void dfs(TreeNode* root,int level){
        if(root==NULL) return;

        if(m_num.count(level)){
            m_num[level]++;
            m_sum[level]+=root->val;
        }else{
            m_num[level]=1;
            m_sum[level]=root->val;
        }

        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
};
```
### 代码 bfs
```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        TreeNode* p,*last=root;
        double sum=0;
        int count=0;
        que.push(root);
        while(!que.empty())
        {
            p=que.front();
            sum+=(double)p->val;
            count++;
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
            if(p==last)
            {
                res.push_back(sum/(double)count);
                sum=count=0;
                last=que.back();
            }
        }
        return res;
    }
};
```
