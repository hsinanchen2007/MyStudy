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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int len=depth(root);            //树的高度
        vector<vector<int>> res(len);   //初始化容器的行数 
        if(root==NULL) return res;
        queue<TreeNode*> q;             //定义队列
        q.push(root);
        vector<int> cur;                //存放每层结点（先声明，放在循环中反复定义，占用内存空间）
        int level=0;                    //记录容器存放到某行
        while(!q.empty())               //层次遍历   
        {
            int n = q.size();           //记录每层结点个数
            while(n--){
                TreeNode* node = q.front();    //获取队头元素
                q.pop();                       //出队
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==0)    //偶数   从左往右
                res[level].insert(res[level].begin(), cur.begin(), cur.end());
            else{             //奇数   从右往左
                    //res[level].insert(res[level].begin(), cur.rbegin(), cur.rend());
                    reverse(cur.begin(), cur.end());
                    res[level].insert(res[level].begin(), cur.begin(), cur.end());
                }
            cur.clear();
            level++;
        }
        return res;
    }
private:
    int depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
};
```
