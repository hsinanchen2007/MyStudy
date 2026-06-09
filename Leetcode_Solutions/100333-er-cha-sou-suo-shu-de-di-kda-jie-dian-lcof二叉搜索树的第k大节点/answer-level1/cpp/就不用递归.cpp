### 解题思路
递归容易爆栈。举例：1280x720大小的图像上，使用连通域算法，如果是递归实现的，更容易爆栈。

说回本题，用stack或queue作为容器存储需要遍历的树节点，再用另一种容器存储每个节点的值：一种是存储到vector，然后降序排序再输出；另一种是直接存储到有序容器set，然后迭代k次输出，注意默认是升序排序因此用反向迭代器。


### 代码
```cpp
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> v;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()) {
            TreeNode* node = dq.back();
            dq.pop_back();

            if(node==NULL) continue;
            v.push_back(node->val);

            dq.push_back(node->left);
            dq.push_back(node->right);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        return v[k-1];
    }
};
```

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        set<int> s;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()) {
            TreeNode* node = dq.back();
            dq.pop_back();

            if(node==NULL) continue;
            s.insert(node->val);

            dq.push_back(node->left);
            dq.push_back(node->right);
        }
        
        set<int>::reverse_iterator it = s.rbegin();
        for (int i = 2; i <= k; ++i) {
            ++it;
        }
        return *it;
    }
};
```