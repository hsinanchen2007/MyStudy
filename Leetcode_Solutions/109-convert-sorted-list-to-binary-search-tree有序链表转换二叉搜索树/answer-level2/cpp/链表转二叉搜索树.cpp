### 解题思路
思路和用数组的差不多
先用快慢指针找到链表中点，那么中点作为根节点，左边链表的作为左子树，右边的链表作为右子树
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
        return foo(head);
    }
    
    TreeNode* foo(ListNode* head){
        if(!head) return NULL;
        if(!head->next){
            TreeNode* root = new TreeNode(head->val);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow,*fast;
        slow = fast = dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = dummy;
        while(pre->next != slow) pre = pre->next;
        pre->next = NULL;//切断左链表
        TreeNode* root = new TreeNode(slow->val);//slow指针的节点作为根节点
        root->left = slow == head? NULL :foo(head);//处理只有两个节点的情况，此时head==slow,左链表应该为空而不是head
        root->right = foo(slow->next);
        return root;
        
    }
};
```