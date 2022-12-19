### 解题思路
这道题的解题过程可以拆解为2步：
1.遍历链表，获取链表的长度n
2.控制for循环遍历的长度，使p结点指向相应位置的结点
3.返回p

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int n = 0;
    struct ListNode*p = head;
    int i;

    while(p){
        ++n;
        p = p->next;
    }

    n = n / 2;
    p = head;
    for(i=0;i<n;i++){
        p = p->next;
    }
    return p;
}
```