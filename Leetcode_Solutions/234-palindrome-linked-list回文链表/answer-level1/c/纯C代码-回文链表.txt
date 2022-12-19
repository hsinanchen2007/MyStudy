bool isPalindrome(struct ListNode* head){
    int size = 0;
    int i = 0;
    int tmp = 0;
    struct ListNode *curNode = head;
    int data[50000] = {0};

    while (curNode != NULL){
        data[size] = curNode->val;
        size++;
        curNode = curNode->next;
    }

    tmp = size/2;
    size = size-1;
    for(i=0; i<tmp; i++){
        if (data[i] != data[size-i]){
            return false;
        }
    }

    return true;
}