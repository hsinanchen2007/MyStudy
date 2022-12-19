### 解题思路
判断链表是否有环。
模板，硬背也要背下来

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {

    if(head==0)return false;
    //快指针每次循环走两个节点，慢指针走一个
    struct ListNode* slowP=head;
    struct ListNode* fastP=head;
    //循环条件就判断快指针到达终点没有，判断顺序也不能反，一定是 快指针不是空指针&&快指针下一个指针也不是空指针
    while(fastP!=0&&fastP->next!=0)
    {
        slowP=slowP->next;
        fastP=fastP->next->next;
        if(slowP==fastP)
            return true;
    }
    return false;
}
```