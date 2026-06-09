
```
// 1.递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if(l1 == NULL) return l2;  // 边界条件，类似归并排序
    
    if(l2 == NULL) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);   // 从后->前 拼接, 首节点是l1， 最终return首节点
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);   // 从后->前 拼接, 首节点是l1
        return l2;
    }

}


// 2.迭代
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* curNode;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = -1;  //可有可无
    
    // struct ListNode* head = l1->val < l2->val ? l1 : l2;   此步骤不需要，头结点也没有什么特殊性
    curNode = head;

    while(l1 && l2) {
        if(l1->val < l2->val){
            curNode->next = l1;
            l1 = l1->next;
            // curNode = curNode->next;
        } else {
            curNode->next = l2;
            l2 = l2->next;
        }
        curNode = curNode->next;
    }

    // if(l1) curNode->next = l1;
    // if(l2) curNode->next = l2;  类似归并排序的归并过程
    curNode->next = l1 != NULL? l1 : l2;

    return head->next;

}
```
