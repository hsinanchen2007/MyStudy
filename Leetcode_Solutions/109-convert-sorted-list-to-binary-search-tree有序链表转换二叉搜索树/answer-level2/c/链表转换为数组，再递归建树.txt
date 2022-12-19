### 解题思路
链表转换为数组，然后再递归建树

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
#define LEN 100000

struct TreeNode* ArrayToBST(int *Array, int left, int right)
{
    if (left >= right) {
        return NULL;
    }

    int mid = (left + right)/2;
    // printf("%d\n", mid);    
    struct TreeNode* treeNode = calloc(1, sizeof(struct TreeNode));
    treeNode->val = Array[mid];
    treeNode->left = ArrayToBST(Array, left, mid);
    treeNode->right = ArrayToBST(Array, mid + 1, right);

    return treeNode;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    /* 链表转换为数组，然后再递归建树 */
    int i = 0;
    int Array[LEN] = {0};
    
    while (head != NULL) {
        Array[i] = head->val;
        i++;
        head = head->next;
    }
    
    return ArrayToBST(Array, 0, i);
}
```