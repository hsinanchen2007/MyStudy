### 解题思路
此处撰写解题思路
1.拷贝链表表头至本地变量，用于返回中间节点。
2.遍历链表计算链表长度。
3.取链表中间节点，注意奇数和偶数。
4.找到中间节点并返回。
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
    int nodenumber = 0;
    int middlenmb = 0;
    int index = 0;
    struct ListNode* ptr;
    ptr = head;
    printf("head->val = %d\n",head->val);
    if(head == NULL) {
        printf("list is empty\n");
    }

    while(head != NULL) {
        head = head->next;
        nodenumber += 1;
    }

    if(nodenumber%2 == 0) {
        middlenmb = nodenumber/2 + 1;
    } else {
        middlenmb = (nodenumber + 1)/2;
    }
    printf("middlenmb = %d\n",middlenmb);

    printf("nodenumber = %d\n",nodenumber);

    for(index = 0; index < (middlenmb - 1); index++) {
        ptr = ptr->next;
    }
    return ptr;
}
```