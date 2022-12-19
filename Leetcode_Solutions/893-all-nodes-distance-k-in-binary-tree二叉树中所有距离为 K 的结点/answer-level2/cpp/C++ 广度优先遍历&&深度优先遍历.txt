**使用队列广度优先遍历**
```
    void helper(TreeNode* node, TreeNode* father, unordered_map<TreeNode*, TreeNode*> &fatherMap){
        if(node == NULL){
            return ;
        }
        else{
            fatherMap[node] = father;
            helper(node->left, node, fatherMap);
            helper(node->right, node, fatherMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> fatherMap;
        helper(root, NULL, fatherMap);
	    queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> seen = {target};
        pair<TreeNode*, int> p(target, 0);
        q.push(p);
        vector<int> res;
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if(p.second == K){
                res.push_back(p.first->val);
            }else{
                if(p.first->left != NULL && seen.find(p.first->left) == seen.end()){
                    pair<TreeNode*, int> left_p(p.first->left, p.second+1);
                    q.push(left_p);
                    seen.insert(p.first->left);
                }
                if(p.first->right != NULL && seen.find(p.first->right) == seen.end()){
                    pair<TreeNode*, int> right_p(p.first->right, p.second+1);
                    q.push(right_p);
                    seen.insert(p.first->right);
                }
                if(fatherMap[p.first] != NULL && seen.find(fatherMap[p.first]) == seen.end()){
                    pair<TreeNode*, int> father_p(fatherMap[p.first], p.second+1);
                    q.push(father_p);
                    seen.insert(fatherMap[p.first]);
                }
                
            }
        }
        return res;
```
**使用栈深度优先遍历（当然也能使用队列）**
```
    void helper(TreeNode* node, TreeNode* father, unordered_map<TreeNode*, TreeNode*> &fatherMap){
        if(node == NULL){
            return ;
        }
        else{
            fatherMap[node] = father;
            helper(node->left, node, fatherMap);
            helper(node->right, node, fatherMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> fatherMap;
        helper(root, NULL, fatherMap);
        stack<pair<TreeNode*, int>> s;
        pair<TreeNode*, int> p(target, 0);
        s.push(p);
        unordered_set<TreeNode*> seen = {target};
        vector<int> res;
        while(!s.empty()){
            pair<TreeNode*, int> p = s.top();
            s.pop();
            if(p.second == K){
                res.push_back(p.first->val);
            }else{
                if(p.first->left != NULL && seen.find(p.first->left) == seen.end()){
                    pair<TreeNode*, int> left_p(p.first->left, p.second+1);
                    s.push(left_p);
                    seen.insert(p.first->left);
                }
                if(p.first->right != NULL && seen.find(p.first->right) == seen.end()){
                    pair<TreeNode*, int> right_p(p.first->right, p.second+1);
                    s.push(right_p);
                    seen.insert(p.first->right);
                }
                if(fatherMap[p.first] != NULL && seen.find(fatherMap[p.first]) == seen.end()){
                    pair<TreeNode*, int> father_p(fatherMap[p.first], p.second+1);
                    s.push(father_p);
                    seen.insert(fatherMap[p.first]);
                }
            }
        }
        return res;
```