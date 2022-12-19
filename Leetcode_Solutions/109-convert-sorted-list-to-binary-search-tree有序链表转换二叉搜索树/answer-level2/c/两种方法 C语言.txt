`\\一、使用空头链表
struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = head;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct ListNode *fast = head, *slow = head, *prev = pHead, *temp;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        prev = prev->next;
        slow = slow->next;
    }
    root->val = slow->val;
    temp = slow->next;
    prev->next = NULL;
    free(slow);
    struct ListNode* qHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    qHead->next = temp;
    root->left = sortedListToBST(pHead->next);
    free(pHead);
    root->right = sortedListToBST(qHead->next);
    free(qHead);
    return root;
}



\\二、使用数组
struct TreeNode* sortedArrayToBST(int* nums, int begin, int end) {
    if (begin > end) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[(end + 1 - begin) / 2 + begin];
    root->left = sortedArrayToBST(nums, begin, (end + 1 - begin) / 2 + begin - 1);
    root->right = sortedArrayToBST(nums, (end + 1 - begin) / 2 + begin + 1, end);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* temp;
    int* nums = malloc(sizeof(int) * 1024);
    int numsSize = 0;
    while (head != NULL) {
        nums[numsSize++] = head->val;
        temp = head;
        head = head->next;
        free(temp);
    }
    struct TreeNode* root = sortedArrayToBST(nums, 0, numsSize - 1);
    free(nums);
    return root;
}`