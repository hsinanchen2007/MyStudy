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

//双指针扫描
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*pre,*p;
    struct ListNode Head;         //增加头结点，所有数据节点操作一致
    p=pre=&Head;
    pre->next=head;
    while(n>0){                   //指针p先行n步
        p=p->next;
        n--;
    }
    while(p->next!=NULL){         //找删除节点的前继节点
        p=p->next;
        pre=pre->next;
    }
    pre->next=pre->next->next;
    return Head.next;
}
```