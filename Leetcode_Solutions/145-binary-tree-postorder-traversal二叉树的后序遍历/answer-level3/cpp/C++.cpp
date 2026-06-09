比起前序与中序遍历，后续非递归遍历多了一个辅助变量pre来判断右节点是否被访问过
```
        stack<TreeNode*> mystack;
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* pre = NULL;
        
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            
            //若右节点已经访问过或者没有右节点  则输出该节点值
            if(!curr->right || pre == curr->right){
                mystack.pop();
                ans.push_back(curr->val);    
                pre = curr;
                curr = NULL;
            }else{
                curr = curr->right;
                pre = NULL;
            }
        }
        return ans;
```

附上前序及中序的非递归算法
```
        stack<TreeNode*> mystack;
        TreeNode* curr = root;
        vector<int> ans;
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                ans.push_back(curr->val);
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            curr = curr->right;
        }
        return ans;

<!-- 中序 -->
        vector<int> ans;
        stack<TreeNode*> mystack;
        TreeNode* curr = root;
        
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
```

