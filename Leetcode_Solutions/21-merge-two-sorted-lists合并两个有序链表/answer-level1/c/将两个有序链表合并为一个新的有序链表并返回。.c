### 解题思路
1.首先创建一个头结点merge，以之作为合并链表的头；
2.依次取有序链表l1、l2中的较小值加入到merge中,直到取完一个链表的全部值
3.把余下的l1/l2拼接到merge尾部

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//人为构造一个头结点，以之作为合并后链表的头结点，并且在整个过程中并不会改变指向
    struct ListNode * merge = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * curr,*pre = merge;
    while(l1 && l2)
    {
        if(l1->val > l2->val)
          {
              curr = l2;        //curr指向当前的较小值的结点,以后用于拼接到merge中
              l2 = l2->next;    //l2链表指向下一个位置
          } 
          else
          {
              curr = l1;
              l1 = l1->next;
          } 
          curr->next = NULL;    //赋值null的目的是让该结点从原来的链表断开
          pre->next = curr;     //将curr结点接入到merge中
          pre = curr;           //目的：pre始终指向merge最后一个结点
    }
    if(l1)
        pre->next = l1;
    else
        pre->next = l2;
    return merge->next;         //merge指向的是头结点，第一个结点不包含有效数据，因此，返回时取merge->next
}
```