### 解题思路
先把链表转化成数组，题目变成了一个easy题目。

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
    TreeNode* dfs(vector<int>& nums,int start,int end)
    {
        if(start == end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = dfs(nums,start,mid);
        root -> right = dfs(nums,mid + 1,end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        while(head != NULL)
        {
            ans.push_back(head -> val);
            head = head -> next;
        }
        return dfs(ans,0,ans.size());
    }
};
```