### 解题思路
这样没问题，一遍就行，甚至不用遍历到链尾。我的思路是：每遍历到一个节点就创建新指针用for循环判断该节点是否为要删除的节点，若为则删除，否则继续遍历，直至遍历到满足的节点。但一定要考虑到特殊情况如只有一个节点的链表和节点数为n的链表要求删除倒数第n个（即删除头结点），否则很容易被特例钻空子。

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
    struct ListNode* headpointer,*pointer;
     headpointer=head;
    while(headpointer->next!=NULL||headpointer->next==NULL){
        pointer=headpointer;
        for(int i=0;i<n;i++){
            pointer=pointer->next;
        }
        if(pointer==NULL){
            headpointer=headpointer->next;
            return headpointer;
        }
        else if(pointer->next==NULL){
            headpointer->next=headpointer->next->next;
            return head;
        }
        
        else{
            headpointer=headpointer->next;
        }
    }
    return head;
}
```