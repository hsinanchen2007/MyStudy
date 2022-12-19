### 解题思路
给定一个当前指针（cur）和cur的next（记为tmp），如果二者的->val相等，则在链表中删除tmp这个结点，然后free内存；如果二者不相等，移动指针到下一个结点。

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
    if(head==NULL)return head;
    struct ListNode* tmp;  //下一个结点
    struct ListNode* cur=head;  //当前结点
    while(cur->next!=NULL){
        tmp=cur->next;
        if(cur->val==tmp->val){
            cur->next=tmp->next;
            free(tmp);
            tmp=NULL;  
        }else cur=cur->next;
    }
    return head;
}
```