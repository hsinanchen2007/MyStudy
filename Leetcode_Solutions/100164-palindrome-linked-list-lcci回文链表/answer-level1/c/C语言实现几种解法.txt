```
bool recursion(struct ListNode** head, int length) {
    if (length == 0)
        return true;
    if (length == 1)
    {
        *head = (*head)->next;
        return true;
    }

    struct ListNode* tmp = *head;
    *head = (*head)->next;
    if (recursion(head, length - 2) == false)
        return false;

    if (tmp->val != (*head)->val) {
        return false;
    }
    *head = (*head)->next;
    return true;
}
```
```
bool isPalindrome(struct ListNode* head){
    // 方法一：时间o(n) 空间o(n)
    // struct ListNode *reHead = NULL;
    // struct ListNode *tmp = head;
    // while(tmp != NULL){
    //     struct ListNode *reTmp = (struct ListNode *)malloc(sizeof(struct ListNode));
    //     reTmp->val = tmp->val;
    //     reTmp->next = reHead;
    //     reHead = reTmp;

    //     tmp = tmp->next;
    // }

    // tmp = head;
    // struct ListNode *reTmp = reHead;
    // while(tmp != NULL){
    //     if(tmp->val != reTmp->val){
    //         while(reHead != NULL){
    //             tmp = reHead->next;
    //             free(reHead);
    //             reHead = tmp;
    //         }
    //         return false;
    //     }
    //     tmp = tmp->next;
    //     reTmp = reTmp->next;

    // }

    // while(reHead != NULL){
    //     tmp = reHead->next;
    //     free(reHead);
    //     reHead = tmp;
    // }
    // return true;

    // 方法二：先统计长度，然后把后一半截取并反转
    // int length = 0;
    // struct ListNode *tmp = head;
    // while(tmp != NULL){
    //     ++length;
    //     tmp = tmp->next;
    // }
    
    // tmp = head;
    // for(int i = 0; i < length / 2; ++i)
    //     tmp = tmp->next;

    // struct ListNode *reHead = NULL;
    // struct ListNode *reTmp;
    // while(tmp != NULL){
    //     reTmp = tmp->next;
    //     tmp->next = reHead;
    //     reHead = tmp;

    //     tmp = reTmp;
    // } 

    // for(int i = 0; i < length / 2; ++i)
    // {
    //     if(reHead->val != head->val)
    //         return false;
    //     reHead = reHead->next;
    //     head = head->next;
    // }
    // return true; -->

    // 方法三：递归，这种方法内存消耗比较大，不适合节点比较多的情况
    // int length = 0;
    // struct ListNode *tmp = head;
    // while(tmp != NULL){
    //     ++length;
    //     tmp = tmp->next;
    // }
    // return recursion(&head, length);


    // 方法四：方法二的改版，只遍历一次，不用一开始统计次数
    struct ListNode *low = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        low = low->next;
        fast = fast->next->next;
    }

    // 总共是奇数个，low要多跳一个
    if(fast != NULL)
        low = low->next;

    // 如果长度<=1，low必然是空，反转后一半
    struct ListNode *rev = NULL;
    while(low != NULL){
        struct ListNode *tmp = low->next;
        low->next = rev;
        rev = low;

        low = tmp;
    }

    while(rev != NULL){
        if(head->val != rev->val)
            return false;
        head = head->next;
        rev = rev->next;
    }

    return true;

}
```