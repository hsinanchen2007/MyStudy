### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> a;
        if(!head) return NULL;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        TreeNode* root = new TreeNode(a[(a.size()-1)/2]);
        root->left = dfs(0,(a.size()-1)/2-1,a);
        root->right = dfs((a.size()-1)/2+1, a.size()-1,a);
        return root;
    }

    TreeNode* dfs(int start, int end, vector<int>& a){
        if(end<start) return NULL;
        int mid = start+(end-start)/2;
        TreeNode* res = new TreeNode(a[mid]);
        res->left = dfs(start,mid-1,a);
        res->right = dfs(mid+1,end,a);
        return res;     
    }
};
```