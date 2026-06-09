### 解题思路
哈哈，效率太低了，

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getListNodeLength(struct ListNode* head);

struct ListNode* getIndexNode(int index, struct ListNode* head);

struct TreeNode* getResult(struct ListNode* head, int start, int end);

struct TreeNode* sortedListToBST(struct ListNode* head);

struct TreeNode* sortedListToBST(struct ListNode* head){
    int length = getListNodeLength(head);
    return getResult(head, 0, length-1);
}

struct TreeNode* getResult(struct ListNode* head, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int rootIndex = (start+end+1)/2;
    struct ListNode* node= getIndexNode(rootIndex, head);
    struct TreeNode* root = (struct TreeNode *)calloc(sizeof(struct TreeNode), 1);

    root->val = node->val;
    root->left = getResult(head, start, rootIndex-1);
    root->right = getResult(head, rootIndex+1, end);

    return root;
}

struct ListNode* getIndexNode(int index, struct ListNode* head) {
    struct ListNode* result = head;
    int i = 0;
    while (i < index) {
        result = result->next;
        i++;
    }
    return result;
}

int getListNodeLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* tmp = head;
    while (tmp != NULL) {
        tmp = tmp->next;
        length++;
    }
    return length;
}
```