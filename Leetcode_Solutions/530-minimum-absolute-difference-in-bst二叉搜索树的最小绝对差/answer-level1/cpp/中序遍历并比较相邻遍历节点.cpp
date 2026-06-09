因为是一颗BST而不是普通二叉树，因而考虑中序遍历，则按遍历顺序得到非递减非负整数序列。

可以在遍历过程中，把每个节点的val存入全局vector，遍历结束后比较vector中相邻两个元素的差值，用于更新得到全局min diff。

显然，大体思路是这样的，不过没有使用vector浪费O(n)空间，只需要在中序遍历BST过程中记录前一个节点，当前节点和前一个节点比较即可。

BST的前序遍历和普通二叉树的前序遍历没什么不同，可以递归实现，也可以非递归实现。

记录节点也有多种方式，可以仅仅是记录节点的val取值，也可以是记录节点指针。

从最naive到最precise，依次实现如下：

1. 遍历所有节点，存储vector，排序，比较相邻元素
完全没有利用BST的特点，也能出结果。它的价值在于能提供正确答案。
```cpp
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;

        deque<TreeNode*> dq;
        dq.push_back(root);

        vector<int> v;
        while(!dq.empty()) {
            TreeNode* node = dq.front();
            dq.pop_front();

            if(node==NULL) {
                continue;
            }
            v.push_back(node->val);
            dq.push_back(node->left);
            dq.push_back(node->right);
        }
        sort(v.begin(), v.end());
        int min_diff = INT_MAX;
        for(int i=1; i<v.size(); i++) {
            int diff = v[i] - v[i-1];
            if(diff < min_diff) {
                min_diff = diff;
            }
        }

        return min_diff;
    }
```

2. 用int& prev来记录前一个节点取值，并利用递归来实现中序遍历
注意传参为引用类型，注意prev区分是否有前驱节点（可比较性）
```cpp
    void dfs(TreeNode* root, int& prev, int& min_diff) {
        if(root==NULL) return;
        // left
        dfs(root->left, prev, min_diff);

        // root
        int cur_diff = root->val - prev;
        min_diff = min(min_diff, cur_diff);
        prev = root->val;

        // right
        dfs(root->right, prev, min_diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int min_diff = INT_MAX;
        dfs(root, prev, min_diff);
        return min_diff;
    }
```

3. 用二级指针替代int* prev，真真正正的记录前一个节点。仍然是递归实现中序遍历。
需要对指针有一定的熟悉度，不至于错误实现/理解不了
```cpp
    void dfs(TreeNode* root, TreeNode** prev, int& min_diff) {
        if (root == NULL) return;

        // left
        dfs(root->left, prev, min_diff);

        // root
        if(*prev!=NULL) {
            min_diff = min(min_diff, root->val-(*prev)->val);
        }
        
        *prev = root;

        // right
        dfs(root->right, prev, min_diff);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        int min_diff = INT_MAX;
        dfs(root, &prev, min_diff);
        return min_diff;
    }
```

4. 非递归DFS实现中序遍历。TreeNode*类型（一级指针）记录前一个节点。
```cpp
    int getMinimumDifference(TreeNode* root) {
        deque<TreeNode*> dq;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        int min_diff = INT_MAX;
        while(cur!=NULL || !dq.empty()) {
            if(cur!=NULL) {
                dq.push_back(cur);
                cur = cur->left;
            } else {
                cur = dq.back();
                dq.pop_back();
                if(prev!=NULL) {
                    min_diff = min(min_diff, cur->val - prev->val);
                }
                prev = cur;

                cur = cur->right;
            }
        }
        return min_diff;
    }
```