### 解题思路
/* 遍历全部节点，并将每一个节点的next指向前一节点 */

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 遍历全部节点，并将每一个节点的next指向前一节点 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode*res=NULL;   //前一节点
    struct ListNode*cur=head;   //当前节点
    while(cur){                 //当前节点非空
        head=head->next;        //下一节点
        cur->next=res;          //当前节点的next指向前一节点
        res=cur;                //前一节点，前进一步至，当前节点
        cur=head;               //当前节点，前进一步至，后一节点
    }
    return res;                 //当前节点为空，前一节点res即原链表的最后一个节点
}
```