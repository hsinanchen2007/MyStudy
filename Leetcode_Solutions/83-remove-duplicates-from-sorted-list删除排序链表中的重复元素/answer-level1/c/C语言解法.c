### 解题思路
    1.重新返回一个指针，不在head上修改。
    2.判断新链表当前指针p的数据域与原链表head的数据域是否相等
        if(相等) head变更到下一节点；
        else 将当前head结点添加入新链表。
    3.只是一种小白新手解法，没有追求效率

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
struct ListNode* p = head,*pr = p;
    while(head!=NULL){
        if(p->val == head->val){
            head = head->next;
        }
        else{
            p->next = head;
            p = p->next;
            head = head->next;
        }
    }
    if(p!=NULL)
         p->next = NULL;
    return pr;
}
```