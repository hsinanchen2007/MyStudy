## 解题思路
先确保p.val < q.val
再层序遍历，返回第一个满足下述条件的节点tmp
+ p.val < tmp.val < q.val
+ p.val == tmp.val < q.val
+ p.val < tmp.val == q.val
## 代码
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p,q);
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            while(n--){
                auto tmp=que.front();
                que.pop();
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
                if((tmp->val > p->val && tmp->val < q->val)||(tmp->val == p->val && tmp->val < q->val)||(tmp->val > p->val && tmp->val == q->val)){
                    return tmp;
                }
            }
        }
        return NULL;
    }
};
```
