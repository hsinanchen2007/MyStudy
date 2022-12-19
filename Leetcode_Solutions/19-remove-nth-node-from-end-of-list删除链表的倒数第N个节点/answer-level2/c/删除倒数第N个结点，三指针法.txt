### 解题思路
一个指针pnode保存前一个元素地址，另外两个指针为快慢指针pslow,pfast，快慢指针相差n个元素的距离，pslow和pnode相差一个距离，当快指针遍历完链表，慢指针指向的就是要删除的元素

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        struct ListNode node;
        node.next=head;
        
        struct ListNode * pnode=&node;
        struct ListNode * pslow=head;
        struct ListNode * pfast=head;
        
        for (int i=0;i<n;i++){
            pfast=pfast->next;
        }
        while(pfast!=NULL){
            pfast=pfast->next;
            pslow=pslow->next;
            pnode=pnode->next;
            
        }
        if(pslow==head){
            head=pslow->next;
        }
        else{
            pnode->next=pslow->next;

        }
        
        return head;
}
```