struct ListNode* mergeNode(struct ListNode*, struct ListNode*);
struct ListNode* sortList(struct ListNode* head){
    
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode *fastNode = head;
    struct ListNode *slowNode = head;
    struct ListNode *breakNode = head;
    
    while(fastNode && fastNode->next) {
        fastNode = fastNode->next->next;
        breakNode = slowNode;
        slowNode = slowNode->next;
    }
    
    breakNode->next = NULL;
    
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(slowNode);
    
    return mergeNode(left, right);
}

struct ListNode* mergeNode(struct ListNode* left, struct ListNode* right) {
    
    if(left == NULL) {
        return right;
    }
    
    if(right == NULL) {
        return left;
    }
    
    if(left->val < right->val) {
        left->next = mergeNode(left->next, right);
        return left;
    }else {
        right->next = mergeNode(left, right->next);
        return right;
    }
} 