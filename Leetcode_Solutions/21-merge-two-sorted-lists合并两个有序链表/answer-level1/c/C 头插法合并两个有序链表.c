### 解题思路
按顺序将 l2 中的结点都插入到 l1 中：
找出 l1 中第一个比当前 l2 结点值要大的结点（注意跟踪 curr1 的前驱），将 l2 中的那个结点插入到 l1。
>PS:一定要注意考虑边界条件；
>1.两个链表中，有一个是空链表；
>2.需要在 l1 的头结点处插入结点；
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//插入法
//将 l2 链表中的结点顺序插入 l1 中
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode *pre1 = NULL;
    struct ListNode *curr1 = l1;
    struct ListNode *temp = l2;
    struct ListNode *curr2 = l2;
    while(curr2){
        while((curr1 != NULL) && (curr1->val < curr2->val || curr1->val == curr2->val)){
            pre1 = curr1;
            curr1 = curr1->next;
        }
        if(!curr1){
            pre1->next = curr2;
            return l1;
        }
        temp = curr2;
        curr2 = curr2->next;
        if(pre1) {
            pre1->next = temp;
            temp->next = curr1;
            pre1 = temp;
        }
        else{//pre == NULL; 说明该插入点在 l1 的头指针前，故需要更改 l1 的头指针;
            temp->next = curr1;
            pre1 = temp;
            l1 = pre1;
        }
        
        
    }
    return l1;
}
```