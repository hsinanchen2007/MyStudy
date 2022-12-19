### 解题思路
使用变量来保存进位， 并且使用虚拟头节点来简化头节点初始化的代码， 使用虚拟头节点， 可以将链表真正的头节点转换为一个子节点， 从而不在需要对其进行特殊操作， 最后将虚拟头节点的 next 返回即是真正的头节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1Cur = l1;
    struct ListNode* l2Cur = l2;
    struct ListNode* dummyHead = (struct ListNode*) calloc (1, sizeof(struct ListNode));
    struct ListNode* cur = dummyHead; // 可以用来简化头节点的初始化代码， 否则就要在后面程序的循环中判断是否为头节点以保存头节点
    int l1Val, l2Val, carry = 0; // carry 记录进位
    while(l1Cur != NULL || l2Cur != NULL || carry == 1){ // 如果最后还有进位， 仍然需要循环
        if(l1Cur != NULL){
            l1Val = l1Cur -> val;
            l1Cur = l1Cur -> next;
        }else{
            l1Val = 0;
        }
        if(l2Cur != NULL){
            l2Val = l2Cur -> val;
            l2Cur = l2Cur -> next;
        }else{
            l2Val = 0;
        }
        cur -> next = (struct ListNode*) calloc(1, sizeof(struct ListNode));
        cur -> next -> val = (l1Val + l2Val + carry) % 10;
        carry = (l1Val + l2Val + carry) / 10;
        cur = cur -> next;
    }
    cur->next = NULL;
    return dummyHead -> next;
}
```