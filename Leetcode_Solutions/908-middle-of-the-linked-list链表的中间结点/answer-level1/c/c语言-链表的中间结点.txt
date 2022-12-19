### 解题思路
设置两个指针mid和p，mid步长为1，p步长为2，当p走到链表尾，mid在中间

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
        struct ListNode *mid=head,*p=head;
        while(p->next&&p->next->next){
            mid=mid->next;
            p=p->next->next;
        }//while
        if(p->next==NULL)return mid;
        return mid->next;
}
```