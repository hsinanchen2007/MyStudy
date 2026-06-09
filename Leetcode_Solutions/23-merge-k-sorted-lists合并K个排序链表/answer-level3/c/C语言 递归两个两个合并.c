```
//递归合并两个链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1 || !l2) return l1?l1:l2;//看了答案优化，把两行if语句判断是否为NULL，合并成一句
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next,l2);//l1的next指针，指向l1->next与l2中val更小的那一个
        return l1;//返回的是小的那一个的头指针，所有的递归调用完，返回l1，也就是链表头指针
        }else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;//返回的是小的那一个的头指针，所有的递归调用完，返回l2，也就是链表头指针
        }
}

//两个两个合并链表
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(0 == listsSize) return NULL;

    struct ListNode* head = lists[0];

//3个链表，循环0，1次
    for(int i = 0; i<listsSize-1; i++){
    head = mergeTwoLists(head,lists[i+1]);
    }
    return head;
}
```
