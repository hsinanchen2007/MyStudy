C++实现，刚开始以为题出的有问题，反复试了下值 发现是中序遍历后的第k个元素的值。1.可以直接中序遍历得到vector[k-1] 或count也可以


```
// 第一种： 中序遍历
    int kthSmallest1(TreeNode* root, int k) {
        if (!root) return -1;
        
        vector<int> vet;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            }else {
                node = st.top();
                st.pop();
                vet.push_back(node->val);
                node = node->right;
            }
        }
       
        return vet[k-1];
    }
```


```
 // 第二种： 和第一种一样 就是不用vector 直接count标记
      int kthSmallest2(TreeNode* root, int k) {
        if (!root) return -1;

        int resultCount = 1;

         stack<TreeNode*> st;
        TreeNode* node = root;
        while(node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            }else {
                node = st.top();
                st.pop();
                if (resultCount ++ == k) {
                    return node->val;
                }
                node = node->right;
            }
        }

            return -1;
      }
```


```
 // 第三种：递归 中序遍历
      int kthSmallest(TreeNode* root, int k) {
            if (!root) return -1;

            int cnt = k;
            int res = 0;
            bfs(root,k,res,cnt);

            return res;
      }

      void bfs(TreeNode* node, int k, int& res,int& cnt) {
          if(!node || cnt <= 0) return;

          bfs(node->left,k,res,cnt);

         if(--cnt == 0) {
             res=node->val;
         }

          bfs(node->right,k,res,cnt);
      }
```


