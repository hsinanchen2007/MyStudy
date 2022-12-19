### 解题思路
使用一个指针squEnd， 指向无重复链表的最后一个元素。逐个检查链表中的值， 遇到与下一个节点数值相同的， 就找到与相同数据的最后一个节点， 并更新 squEnd

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
    struct ListNode* dummyHead = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    dummyHead -> next = head;
    struct ListNode* squEnd = dummyHead; // 指向无重复链表的最后一个元素， 初始值指向 dummyHead 代表还不存在无重复链表
    struct ListNode* cur = head; // 审查的元素
    struct ListNode* delNode = NULL;
    while(cur != NULL && cur -> next != NULL){
        if(cur -> val == cur -> next -> val){
            while(cur -> next != NULL && cur -> val == cur -> next -> val){ // 找到与相同数据的最后一个节点， 如果循环到末尾， 也要结束循环
                delNode = cur; // 注意要释放内存
                cur = cur -> next;
                free(delNode);
            }
            delNode = cur;
            cur = cur -> next;
            squEnd -> next = cur;
            free(delNode);
        }else{
            squEnd = cur; // 当前元素鱼下一个元素不同， 直接将 squEnd 更新到 cur 
            cur = cur -> next;
        }
        
    }
    struct ListNode* ret = dummyHead -> next;
    free(dummyHead);
    return ret;
}
```