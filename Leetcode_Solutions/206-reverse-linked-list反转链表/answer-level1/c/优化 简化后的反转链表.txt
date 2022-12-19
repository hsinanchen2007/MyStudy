### 解题思路
这是这个问题的第二次题解
这种方式更容易理解
上一种采用的方式之所以那么复杂 是因为每次反转的同时也将head给确定了。这次采用的方式是最后才确定head的，个人感觉这种方式更加优秀

强调一下这种方式的核心是cur，也就是将要反转的那个节点就是cur。pion指针(pioneer)也是由cur确定的。

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
    struct ListNode *pre,*cur,*pion;
    pre=NULL;
    cur=head;
    while(cur!=NULL){
        pion=cur->next;
        cur->next=pre;
        pre=cur;
        cur=pion;
    }
    return pre;

}


```