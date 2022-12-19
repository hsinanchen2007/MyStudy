除了递归和迭代法，再提供一种[Morris方法](https://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion)，进行倒序的中序遍历搜索`KthLargest`节点的值。
- 时间复杂度$O(N)$
- 空间复杂度$O(1)$
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int kthLargest(struct TreeNode* root, int k){
    struct TreeNode* curr = root;
    int count = 0;
    int ans;
    while(curr != NULL){
        if(curr->right == NULL){
            count++;
            if(count == k){
                ans = curr->val;
                break;
            }
            curr = curr->left;
        }
        else {
            struct TreeNode* pre = curr->right;
            while(pre->left != NULL && pre->left != curr){
                pre = pre->left;
            }

            if(pre->left == NULL){
                pre->left = curr;
                curr = curr->right;
            }
            else {
                pre->left = NULL;
                count++;
                if(count == k){
                    ans = curr->val;
                    break;
                }
                curr = curr->left;
            }
        }
    }
    return ans;
}
```
