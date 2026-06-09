### 解题思路
最简单的做法，把所有的数字都取出来存入一个数组，然后重新构成链表即可。
比如：
```C
1->2->3->4->5->NULL ---> 1 2 3 4 5 ---> 5->4...;
```
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int q[100000];
struct ListNode* reverseList(struct ListNode* head){
    if(!head) return; //空链表直接返回；
    int len = 0;
    struct ListNode *p = head;
    while(p){ //取出所有的值；
        len++;
        q[len] = p->val;
        p = p->next;
    }
    p = head;
    for(int i = len; i >= 1; i--){ //重组链表；
        p->val = q[i];
        p = p->next;
    }
    return head;
}
```