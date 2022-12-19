单遍遍历，设置两个标记指针，一个标记遍历位置，一个标记上个节点：
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *l1 = head;
    struct ListNode *result = NULL;
    struct ListNode *lastNode = NULL;
    while (l1) {
        if (l1->val == val) {
            if (lastNode != NULL) {
                lastNode->next = l1->next;
            }
        }else{
            lastNode = l1;
            if (result == NULL) {
                result = lastNode;
            }
        }
        
        l1 = l1->next;
    }
    return result;
}