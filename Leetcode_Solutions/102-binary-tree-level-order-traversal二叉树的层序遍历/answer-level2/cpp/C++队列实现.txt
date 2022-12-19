如果答案不要求每一层的数据放在一块，这题就更好写了。
既然要求每层的数据放在一块，那么就利用一个二元组pair记录结点和其所在的层数。
如果当前弹出的结点与队列中下一个元素的层数一致，就将弹出结点的值插入临时数组中，否则将弹出结点的值插入到临时数组中，并保存到结果数组中，清空临时数组以便下回使用。
```
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return ans;
        vector<int> tmp;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            int num=q.front().second;
            int val=q.front().first->val;
            if(q.front().first->left!=NULL)
                q.push(make_pair(q.front().first->left,num+1));
            if(q.front().first->right!=NULL)
                q.push(make_pair(q.front().first->right,num+1));

            q.pop();
            if(q.empty())
            {//q已经空了
                tmp.push_back(val);
                ans.push_back(tmp);
                break;
            }
            else
            {//q未空
                if(num==q.front().second)
                {//与队列中下一个结点的层数一样
                    tmp.push_back(val);
                }
                else{
                    tmp.push_back(val);
                    ans.push_back(tmp);
                    vector<int>().swap(tmp);
                }
            }
        }
        return ans;
    }
};
```
