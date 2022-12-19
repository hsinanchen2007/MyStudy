### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int c;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL&&c==0)
    return NULL;
    //c为进位
    l1=l1!=NULL?(c+=l1->val,l1->next):l1;
    l2=l2!=NULL?(c+=l2->val,l2->next):l2;
    //如果l1为空说明l1加完了,就给进位加0(不变),l1始终不变,不为空则加l1当前位值,l1移向下一位,l2同理,直到l1,l2为空,c为0
    struct ListNode* cur=(struct ListNode*)malloc(sizeof(struct ListNode));
    cur->val=c%10;
    c=c/10;
    cur->next=addTwoNumbers(l1,l2);
    return cur;
}
```