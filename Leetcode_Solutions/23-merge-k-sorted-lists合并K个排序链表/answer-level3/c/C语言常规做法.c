该题由于链表数量较大，适合用递归的方法，当链表数量大于2时，将链表数组平分，时间复杂度为O(log N)。
算法的具体代码实现其实不难，base case也不难理解，较难的是归纳的部分。处理好归纳的部分，该题还是比较容易解决的。
```c
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0) return 0;
    else if(listsSize==1) return lists[0];
    else if(listsSize==2){
        struct ListNode header;
        header.next=lists[0];
        lists[0]=&header;
        struct ListNode* tmp;
        while(lists[1]!=0){
            while(lists[0]->next&&lists[0]->next->val<lists[1]->val) lists[0]=lists[0]->next;
            tmp=lists[1]->next;
            lists[1]->next=lists[0]->next;
            lists[0]->next=lists[1];
            lists[1]=tmp;
        }
        return header.next;
    }
    struct ListNode** listsA[listsSize/2], **listsB[listsSize-listsSize/2];
    short i;
    for(i=0;i<listsSize/2;i++) listsA[i]=lists[i];
    for(i=listsSize/2;i<listsSize;i++) listsB[i-listsSize/2]=lists[i];
    struct ListNode** res[2]={mergeKLists(listsA,listsSize/2),mergeKLists(listsB,listsSize-listsSize/2)};
    return mergeKLists(res,2);
}
```