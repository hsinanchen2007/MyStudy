
### 代码
```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *fast = head, *slow = head ,*front = nullptr;
        while(fast && fast->next){
            front = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if(front) front->next = nullptr;
        if(head == slow) return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
```