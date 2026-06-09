### 解题思路
新申请一个列表，分别解析原始列表中的节点，倒排。
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
    struct ListNode *newlist, *newhead, *temp;
    int flag = 0;
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    newhead = head;
    
    newlist = temp;
    while(newhead != NULL) {
        if (flag == 0) {
            temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->next = NULL;
            temp->val = newhead->val;
            flag = 1;
            newlist = temp;
            newhead = newhead->next;
            continue;
        }
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = newlist;
        temp->val = newhead->val;
        newlist = temp;
        newhead = newhead->next;
    }
    for (temp = newlist; temp != NULL; temp = temp->next) {
        printf("temp->val=%d\n", temp->val);
    }

    return newlist;
}
```