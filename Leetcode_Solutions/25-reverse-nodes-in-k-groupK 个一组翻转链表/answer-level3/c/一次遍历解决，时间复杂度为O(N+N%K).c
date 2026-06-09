一次遍历进行链表反转，思路：遍历的同时，然后进行K个节点反转一次。遍历一遍之后，最后剩余n%k个节点顺序需要恢复正常顺序，最后的n%k个节点反转第二次，恢复正常顺序，时间复杂度为O(N+N%K)

struct ListNode* reverseList(struct ListNode* head);
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (k == 1) {
        return head;
    }
    struct ListNode *resultHeader = NULL,*resultRear = NULL;
    struct ListNode *kHeader = NULL ,*kRear = NULL;
    int count = 0;
    int index = 0;
    while (head) {
        struct ListNode *temp = head->next;
        head->next = kHeader;
        if (kRear == NULL) {
            kRear = head;
        }
        kHeader = head;
        head = temp;
        index++;
        if (index == k) {
            if (resultHeader == NULL) {
                resultHeader = kHeader;;
            }
            if (resultRear == NULL) {
                resultRear = kRear;
            }else{
                resultRear->next = kHeader;
                resultRear = kRear;
            }
            kHeader = NULL;
            kRear = NULL;
            index = 0;
        }
        count++;
    }
    //余index个不需要反转,需要重新反转 kHeader -> kRear
    if (index<k && index>0) {
        if (resultRear == NULL) {
            return reverseList(kHeader);
        }
        resultRear->next = reverseList(kHeader);
    }
    return resultHeader;
}

//链表反转
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *storage = NULL;
    while (head) {
        struct ListNode *temp1 = head->next;
        head->next = storage;
        storage = head;
        head = temp1;
    }
    return storage;
}