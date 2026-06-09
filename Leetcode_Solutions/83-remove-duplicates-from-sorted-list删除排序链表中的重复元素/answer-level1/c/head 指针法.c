### 解题思路
1.保留head
2.定义一个指针，遍历链表，除去重复元素，也就是改变前一个元素的next指针

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
    struct ListNode *currentNode;
    currentNode = head;
    if(currentNode == NULL) return NULL;
    while(currentNode->next != NULL)
    {
        if(currentNode->val == currentNode->next->val)
        {
            currentNode->next = currentNode->next->next;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
    return head;
}
```