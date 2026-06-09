# C语言，遍历查找重复节点

使用一个变量保存 **前一个结点**。  
把所有重复的节点都遍历过，找到下一个不重复节点。  
将**前一个节点**连接到下一个不重复节点即可。  

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p = head;
    struct ListNode* next = NULL;
    struct ListNode* pre = NULL;

    while(p) {
        bool repeated = false;
        next = p->next;
        while(next) {
            if(p->val == next->val) {
                next = next->next;
                repeated = true;
            } else {
                break;
            }
        }
        if (repeated) {
            if(pre) {
                pre->next = next;
            } else {
                head = next;
            }
        } else {
            pre = p;
        }
        p = next;
    }
    return head;
}
```
