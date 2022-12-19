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


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p,*pre=NULL;// p功能指针，保存剩余head；pre为新列
    while(head){
        p=head->next;//保存剩余head
        head->next=pre;//当前新列接在新加入节点后
        pre=head;//将新节点赋给新列指针pre
        head=p;//p归还剩余head
    }
    return pre;
}
```