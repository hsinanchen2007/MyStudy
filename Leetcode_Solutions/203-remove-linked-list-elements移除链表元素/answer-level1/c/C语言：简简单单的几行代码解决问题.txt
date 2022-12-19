
```
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode  ret_head;
    struct ListNode* fir_node = &ret_head;
    struct ListNode* sec_node = head;
    ret_head.next = NULL;
    while (sec_node != NULL) {
        while (sec_node != NULL && sec_node->val == val) {
            struct ListNode* tmp = sec_node->next;
            free(sec_node);
            sec_node = tmp;
        }
        fir_node->next = sec_node;
        if (sec_node == NULL) break; 
        fir_node = sec_node;
        sec_node = sec_node->next;
    }
    return ret_head.next;
}
```
