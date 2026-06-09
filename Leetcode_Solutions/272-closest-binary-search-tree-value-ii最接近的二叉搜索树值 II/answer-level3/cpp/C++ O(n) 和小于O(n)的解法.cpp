先来看O(n)的解法。 中序遍历， 维护一个size为k的最大堆。 堆中存储的是pair{diff, val};
遍历完成后把堆中数据拷贝到结果中即可。 
```
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorderTraversal(root, target, k);
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorderTraversal(TreeNode* root, double target, int k){
        if(root == nullptr) return;
        inorderTraversal(root->left, target, k);
        double diff = abs(root->val - target);
        if(q.size() < k){
            q.push({diff, root->val});
        }
        else if(diff < q.top().first){
            q.pop();
            q.push({diff, root->val});
        }
        inorderTraversal(root->right, target, k);
    }
private:
    priority_queue<pair<double, int>> q;
};
```

小于O(n)的解法， 改变非常小，其实就是利用二叉搜索树的性质，发现diff大于堆顶， 就可以提前return， 不在继续遍历当前分支了
```
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorderTraversal(root, target, k);
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorderTraversal(TreeNode* root, double target, int k){
        if(root == nullptr) return;
        inorderTraversal(root->left, target, k);
        double diff = abs(root->val - target);
        if(q.size() < k){
            q.push({diff, root->val});
        }
        else if(diff < q.top().first){
            q.pop();
            q.push({diff, root->val});
        }
        else{
            return;
        }
        inorderTraversal(root->right, target, k);
    }
private:
    priority_queue<pair<double, int>> q;
};
```