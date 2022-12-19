这道题考察树的基本遍历,下面是迭代方法实现.
```
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> v1 = vector<int>(); // 树1数组
        vector<int> v2 = vector<int>(); // 树2数组
        stack<TreeNode*> sequentialTraversal = stack<TreeNode*>(); // 中序遍历栈
        
        /**
         * 中序遍历
         */
        while (!sequentialTraversal.empty() || root1!= nullptr){
            while (root1!= nullptr){
                sequentialTraversal.push(root1);
                root1 = root1->left;
            }
            root1 = sequentialTraversal.top();
            sequentialTraversal.pop();
            v1.push_back(root1->val);
            root1 = root1->right;
        }

        /**
         * 中序遍历
         */
        while (!sequentialTraversal.empty() || root2!= nullptr){
            while (root2!= nullptr){
                sequentialTraversal.push(root2);
                root2 = root2->left;
            }
            root2 = sequentialTraversal.top();
            sequentialTraversal.pop();
            v2.push_back(root2->val);
            root2 = root2->right;
        }
        
        /**
         * merge 与分治算法merge过程相同
         */
        int i1 = 0;
        int i2 = 0;
        vector<int> res = vector<int>();
        while (i1 <= v1.size() || i2 <= v2.size()){
            if (i1 == v1.size()){ // 数组1遍历空
                for (int i = i2;i2<v2.size();i2++){
                    res.push_back(v2[i2]);
                }
                break;
            }
            
            if (i2 == v2.size()){ // 数组2遍历空
                for (int i = i1;i1<v1.size();i1++){
                    res.push_back(v1[i1]);
                }
                break;
            }

            if (v1[i1] >= v2[i2]){
                res.push_back(v2[i2]);
                i2++;
            } else{
                res.push_back(v1[i1]);
                i1++;
            }
        }
        return res;
    }
```
