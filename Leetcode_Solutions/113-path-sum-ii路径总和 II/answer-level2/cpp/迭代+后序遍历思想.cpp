这道题看了快两天了，总是卡在“temp数组和stack同时消掉元素，导致最终结果不全“”，原因是已经做习惯DFS的先序和BFS，导致上来就这么写，结果必错；
代码借鉴了王道数据结构P130，第三题；
其中，后序遍历因栈中元素最后出栈，故其中比保留当前访问节点的祖先节点；可用于求根节点到子节点的路径以及两节点的公共祖先问题；
学习知识的过程还是要踏实，最近急于刷题，忽略了对基本知识的深入挖掘，慎重慎重。
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return {};
        TreeNode* p = root;
        stack<pair<TreeNode*,int>>s;
        vector<vector<int> >ans;
        vector<int>temp;
        int n = 0;
        TreeNode* r = NULL;                             //r用来标记是否已访问过
        while(p||!s.empty())
        {
            while(p)
            {
                temp.push_back(p->val);
                n += p->val;
                s.push(pair<TreeNode*,int>(p,n));
                p = p->left;
            }
            p = s.top().first;
            n = s.top().second;
            if(n==sum&&!p->left&&!p->right)
                ans.push_back(temp);                     //如果temp数组满足要求，进ans
            if(p->right&&p->right!=r)                    //右孩子不空且未访问过；    
            {
                p = p->right;
            }
            else
            {
                s.pop();
                temp.pop_back();
                r = p;                                  //r标记当前节点已访问
                p = NULL;                               //重置p指针，不然栈会不停地进出同一节结点
            }
        }
        return ans;
    }
};
```
