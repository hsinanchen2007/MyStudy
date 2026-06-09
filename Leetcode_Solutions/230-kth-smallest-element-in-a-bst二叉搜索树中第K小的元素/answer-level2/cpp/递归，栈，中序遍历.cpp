### 解题思路

这道题先写出来了递归的方法。中序遍历。使用一个辅助数组来保存每个节点的值。最后取出第K个数就是答案。

然后发现还可以用栈的方法。 先把左边的节点全部压入栈。依次取出栈最小的数。中序遍历可以用栈。。

### 代码

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
    // 执行用时 :28 ms, 在所有 C++ 提交中击败了51.72% 的用户
    // 内存消耗 :24.5 MB, 在所有 C++ 提交中击败了5.73%的用户
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        kthSmallestCore(root, temp);
        return temp[k-1];
    }
    
    void kthSmallestCore(TreeNode* root, vector<int>& temp){
        if(!root->left&&!root->right){
            temp.push_back(root->val);
            return;
        }

        if(root->left) kthSmallestCore(root->left, temp);
        temp.push_back(root->val);
        if(root->right) kthSmallestCore(root->right, temp);

    }



    // 执行用时 :36 ms, 在所有 C++ 提交中击败了22.08% 的用户
    // 内存消耗 :24.1 MB, 在所有 C++ 提交中击败了5.73%的用户
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int num = 0;
        while(root||!s.empty()){
            while(root){//先把左子树全部压进去。
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ++num;
            if(num==k){
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};
```