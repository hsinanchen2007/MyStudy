
```
 // 第一种：递归
   vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vet;
        if (root == NULL) return vet;
        recursiveLevelOrder(root, 0, vet);
        return vet;
   }

   void recursiveLevelOrder(TreeNode *node,int depth,vector<vector<int>>&vet) {
       if (node == NULL) return;

       if (depth == vet.size()) { // 0,0  1,1  这里边界是当前深度==vector<vector<int>> size()
            vet.push_back(vector<int>());
       }

        vet[depth].push_back(node->val); // [[3]]  [[3][9]] 
        recursiveLevelOrder(node->left,depth+1,vet);
        recursiveLevelOrder(node->right,depth+1,vet);
   }

    // 第二种：迭代
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> vet;
        if (root == NULL) return vet;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> ve;
            int width = q.size();
            while(width-- > 0){  // 这里没必要for还定义一个变量，直接while -- 会更好些
                TreeNode *node = q.front();
                ve.push_back(node->val);                                              
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            vet.push_back(ve);
        }

        return vet;
    }
```
