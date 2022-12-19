**层次遍历，每一次结束时计算计算平均值**
```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;
        long tmp = 0, cnt = 0;
        TreeNode *p, *last = root, *newLast;
        q.push(root);

        while(!q.empty()){
            p = q.front();
            q.pop();
            tmp += p->val;
            cnt++;

            if(p->left){
                q.push(p->left);
                newLast = p->left;
            }
            if(p->right){
                q.push(p->right);
                newLast = p->right;
            }
            if(p == last){
                v.push_back((double)tmp / cnt);
                last = newLast;
                tmp = 0;
                cnt = 0;
            }
        }
        return v;
    }
};
```