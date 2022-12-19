**思路：**
关于二叉树的大部分的题目，无非是前序，中序，后序和层次遍历，再者就是递归。
所以这题我们很容易的想到可以用到queue容器来进行层次遍历。
但是对于题目要求的：**第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印。**我们也可以很容易的观察到，深度不同所以顺序不同，故我们可以在queue容器中存储该结点的深度信息和结点信息，根据深度来决定是否反转结点值。
然后用size来标记每一层的节点数量，在queue容器中进行层次遍历即可解得。

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root) return {};
        vector<vector<int>> res;
        vector<int> v;
        queue<pair<TreeNode*,int>>Q;
        int depth=0,size=1;
        TreeNode* tmp=NULL;
        Q.push({root,1});
        while(!Q.empty())
        {
            while(size-->0)
            {
                tmp=Q.front().first;
                depth=Q.front().second;
                Q.pop();

                if(tmp->left){
                    Q.push({tmp->left,depth+1});
                }
                if(tmp->right){
                    Q.push({tmp->right,depth+1});
                }

                v.push_back(tmp->val);
            }
            if(depth%2==0)
                reverse(v.begin(),v.end());
            res.push_back(v);
            v.clear();
            size=Q.size();
        }
        return res;
    }
};
```
