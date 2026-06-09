深度优先搜索递归形式的解法:
```
 int minDepth(TreeNode* root) 
{
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return minDepth(root->left) + 1;
        return minDepth(root->left) > minDepth(root->right) ? minDepth(root->right) + 1 : minDepth(root->left) + 1;
}
```
广度优先搜索非递归形式解法:
```
int minDepth(TreeNode* root) 
{
        int min = 0;
        if(!root) return min;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* p = q.front();
                q.pop();
                if(!p->left && !p->right) return min + 1;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);           
            }
            min++;
        }
        return min;
 }
```
本题关键在于叶结点，找到叶结并记录深度比较就能解了;
对于这类问题，BFS显然优于DFS,因为DFS需要所有结点都走一遍，而BFS层次遍历,找到第一个叶结点便返回最小值